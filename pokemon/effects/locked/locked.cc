#include "locked.h"

#include <random>

using json = nlohmann::json;

Locked::Locked(const json& effects) {
  if (!effects.contains("locked")) return;
  for (auto& item : effects["locked"].items()) {
    int hits = std::stoi(item.key());
    float probability = item.value();
    prob[hits] = probability;
  }
}

const std::map<int, float>& Locked::getProb() const { return prob; }

bool Locked::hasEffect() const { return !prob.empty(); }

int Locked::selectDuration(std::mt19937& rng) const {
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