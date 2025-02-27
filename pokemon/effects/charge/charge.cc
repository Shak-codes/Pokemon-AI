#include "charge.h"

#include "../../../lib/json.hpp"

using json = nlohmann::json;

Charge::Charge(const json& effects) {
  if (effects.contains("charge")) {
    for (auto& [key, value] : effects["charge"].items()) {
      int hits = std::stoi(key);
      float probability = value;
      prob[hits] = probability;
    }
  }
}

const std::map<int, float>& Charge::getProb() const { return prob; }

bool Charge::hasEffect() const { return !prob.empty(); }