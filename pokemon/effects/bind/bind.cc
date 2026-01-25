#include "bind.h"

#include <random>

using json = nlohmann::json;

Bind::Bind(const json& effects) {
  if (!effects.contains("bind")) return;

  for (auto& item : effects["bind"].items()) {
    int hits = std::stoi(item.key());
    float probability = item.value();
    prob[hits] = probability;
  }
}

const std::map<int, float>& Bind::getProb() const { return prob; }

bool Bind::hasEffect() const { return !prob.empty(); }

int Bind::selectDuration(std::mt19937& rng) const {
  if (prob.empty()) return 0;

  float total = 0.0f;
  for (const auto& entry : prob) {
    total += entry.second;
  }
  if (total <= 0.0f) return 0;

  std::uniform_real_distribution<float> dist(0.0f, total);
  float roll = dist(rng);
  float cumulative = 0.0f;

  for (const auto& entry : prob) {
    cumulative += entry.second;
    if (roll <= cumulative) {
      return entry.first;
    }
  }

  return prob.rbegin()->first;
}