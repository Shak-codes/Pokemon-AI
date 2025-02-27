#include "drain.h"

#include "../../../lib/json.hpp"
using json = nlohmann::json;

Drain::Drain(const json& effects) {
  if (!effects.contains("drain")) return;
  value = effects["drain"];
}

bool Drain::hasEffect() const { return value > 0.0f; }

float Drain::getValue() const { return value; }