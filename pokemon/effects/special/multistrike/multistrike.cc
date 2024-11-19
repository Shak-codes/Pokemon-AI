#include "../../../../lib/json.hpp"
#include "multristrike.h"

using json = nlohmann::json;

Multistrike::Multistrike(const json& data) {
  if (data.contains("hits")) {
    for (auto& [key, value] : data["hits"].items()) {
      int hits = std::stoi(key);
      float probability = value;
      prob[hits] = probability;
    }
  }
}

const std::map<int, float>& Multistrike::getProb() const { return prob; }

bool Multistrike::isMultistrike() const { return !prob.empty(); }