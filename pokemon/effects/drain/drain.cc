#include "drain.h"

#include "../../../lib/json.hpp"
using json = nlohmann::json;

Drain::Drain(const json& effects) {
  if (!effects.contains("drain")) return;
  percentage = effects["drain"];
}

bool Drain::hasEffect() const { return percentage > 0.0f; }