#include "healing.h"

#include "../../../lib/json.hpp"
using json = nlohmann::json;

Healing::Healing(const json& effects) {
  if (!effects.contains("healing")) return;
  if (effects["healing"]["type"] == "health") {
    type = HealingTypes::HEALTH;
  } else
    type = HealingTypes::DAMAGE;
  value = effects["healing"]["value"];
}

bool Healing::hasEffect() const { return type != HealingTypes::NONE; }

float Healing::getValue() const { return value; }

int Healing::calculateHealing(int maxHP, int damageDealt) const {
  if (!hasEffect() || maxHP <= 0) return 0;

  float rawHealing = 0.0f;
  if (type == HealingTypes::HEALTH) {
    rawHealing = static_cast<float>(maxHP) * value;
  } else if (type == HealingTypes::DAMAGE) {
    if (damageDealt <= 0) return 0;
    rawHealing = static_cast<float>(damageDealt) * value;
  }

  int healing = static_cast<int>(std::floor(rawHealing));
  if (healing < 0) return 0;
  if (healing > maxHP) return maxHP;
  return healing;
}