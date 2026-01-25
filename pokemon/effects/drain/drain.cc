#include "drain.h"

#include "../../../lib/json.hpp"
using json = nlohmann::json;

Drain::Drain(const json& effects) {
  if (!effects.contains("drain")) return;
  value = effects["drain"];
}

bool Drain::hasEffect() const { return value > 0.0f; }

float Drain::getValue() const { return value; }

int Drain::calculateHealing(int damageDealt) const {
  if (!hasEffect() || damageDealt <= 0) return 0;
  float rawHealing = static_cast<float>(damageDealt) * value;
  int healing = static_cast<int>(std::floor(rawHealing));
  return healing < 0 ? 0 : healing;
}