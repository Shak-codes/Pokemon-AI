#include "../../../lib/json.hpp"
#include "multristrike.h"

using json = nlohmann::json;

Multistrike::Multistrike(const json& effects) {
  if (!effects.contains("multistrike")) return;
  for (auto& [key, value] : effects["multistrike"].items()) {
    int hits = std::stoi(key);
    float probability = value;
    prob[hits] = probability;
  }
}

const std::map<int, float>& Multistrike::getProb() const { return prob; }

bool Multistrike::hasEffect() const { return !prob.empty(); }