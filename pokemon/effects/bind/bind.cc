#include "bind.h"

#include "../../../lib/json.hpp"

using json = nlohmann::json;

Bind::Bind(const json& effects) {
  if (effects.contains("bind")) {
    for (auto& [key, value] : effects["bind"].items()) {
      int hits = std::stoi(key);
      float probability = value;
      prob[hits] = probability;
    }
  }
}

const std::map<int, float>& Bind::getProb() const { return prob; }

bool Bind::hasEffect() const { return !prob.empty(); }