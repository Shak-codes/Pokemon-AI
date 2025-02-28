#include "statModifiers.h"

#include "../../../lib/json.hpp"
using json = nlohmann::json;

StatModifiers::StatModifiers(const json& statusEffects) {
  for (const auto& [key, value] : statusEffects.items()) {
    if (value.contains("chance") && value.contains("value")) {
      this->mods[key] = {value["value"].get<int>(),
                         value["chance"].get<float>()};
    } else {
      this->mods[key] = {1, 1.0f};
    }
  }
}

std::pair<int, float> StatModifiers::getMod(const std::string& key) const {
  auto it = mods.find(key);
  return it != mods.end() ? it->second : std::make_pair(0, 0.0f);
}

bool StatModifiers::hasEffect() const { return !mods.empty(); }
