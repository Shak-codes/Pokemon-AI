#include "statModifiers.h"

#include <random>

#include "../../stats/mods/mods.h"
#include "../../../lib/json.hpp"
using json = nlohmann::json;

StatModifiers::StatModifiers(const json& statusEffects) {
  for (auto it = statusEffects.begin(); it != statusEffects.end(); ++it) {
    const std::string& key = it.key();
    const json& value = it.value();
    if (value.contains("chance") && value.contains("value")) {
      this->mods[key] =
          std::make_pair(value["value"].get<int>(),
                         value["chance"].get<float>());
    } else {
      this->mods[key] = std::make_pair(1, 1.0f);
    }
  }
}

std::pair<int, float> StatModifiers::getMod(const std::string& key) const {
  auto it = mods.find(key);
  return it != mods.end() ? it->second : std::make_pair(0, 0.0f);
}

bool StatModifiers::hasEffect() const { return !mods.empty(); }

const std::map<std::string, std::pair<int, float>>& StatModifiers::getAllMods()
    const {
  return mods;
}

static void applyModToTarget(Mods& targetMods, const std::string& stat,
                             int value) {
  if (stat == "attack") {
    targetMods.modifyAttack(value);
  } else if (stat == "defense") {
    targetMods.modifyDefense(value);
  } else if (stat == "special") {
    targetMods.modifySpecial(value);
  } else if (stat == "speed") {
    targetMods.modifySpeed(value);
  } else if (stat == "accuracy") {
    targetMods.modifyAccuracy(value);
  } else if (stat == "evasion") {
    targetMods.modifyEvasion(value);
  }
}

static float clampChance(float chance) {
  if (chance < 0.0f) {
    return 0.0f;
  }
  if (chance > 1.0f) {
    return 1.0f;
  }
  return chance;
}

bool StatModifiers::apply(Mods& targetMods, std::mt19937& rng) const {
  if (mods.empty()) {
    return false;
  }

  std::uniform_real_distribution<float> dist(0.0f, 1.0f);
  bool appliedAny = false;

  for (auto it = mods.begin(); it != mods.end(); ++it) {
    const std::string& stat = it->first;
    const std::pair<int, float>& mod = it->second;
    float chance = clampChance(mod.second);
    if (chance <= 0.0f) {
      continue;
    }

    if (chance >= 1.0f || dist(rng) <= chance) {
      applyModToTarget(targetMods, stat, mod.first);
      appliedAny = true;
    }
  }

  return appliedAny;
}
