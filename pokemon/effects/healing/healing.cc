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