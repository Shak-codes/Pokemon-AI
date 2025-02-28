#include "locked.h"

#include "../../../lib/json.hpp"

using json = nlohmann::json;

Locked::Locked(const json& effects) {
  if (!effects.contains("locked")) return;
  for (auto& [key, value] : effects["locked"].items()) {
    int hits = std::stoi(key);
    float probability = value;
    prob[hits] = probability;
  }
}

const std::map<int, float>& Locked::getProb() const { return prob; }

bool Locked::hasEffect() const { return !prob.empty(); }