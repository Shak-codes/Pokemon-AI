#include "status.h"

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
