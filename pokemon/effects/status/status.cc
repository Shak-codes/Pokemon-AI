#include "status.h"

#include "../../../lib/json.hpp"

using json = nlohmann::json;

Status::Status(const json& status) {
  for (const auto& [key, value] : status.items()) {
    statusEffects[key] = value.get<float>();
  }
}

bool Status::hasStatusEffects() const {
  for (const auto& [key, value] : statusEffects) {
    if (value > 0.0f) {
      return true;
    }
  }
  return false;
}

float Status::getStatusEffect(const std::string& key) const {
  auto it = statusEffects.find(key);
  if (it != statusEffects.end()) {
    return it->second;
  }
  return 0.0f;
}
