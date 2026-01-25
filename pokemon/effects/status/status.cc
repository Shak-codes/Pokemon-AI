#include "status.h"

#include <string>
#include <vector>

#include "../../../lib/json.hpp"
using json = nlohmann::json;

Status::Status(const json& statusEffects) {
  for (const auto& [key, value] : statusEffects.items()) {
    this->statusEffects[key] = value.get<float>();
  }
}

bool Status::hasEffect() const { return !statusEffects.empty(); }

std::map<std::string, float> Status::getStatusEffect() const {
  return statusEffects;
}

float Status::getChance(const std::string& status) const {
  auto it = statusEffects.find(status);
  if (it != statusEffects.end()) {
    return it->second;
  }
  return 0.0f;
}

std::vector<std::string> Status::getStatuses() const {
  std::vector<std::string> statuses;
  for (const auto& [key, value] : statusEffects) {
    statuses.push_back(key);
  }
  return statuses;
}
