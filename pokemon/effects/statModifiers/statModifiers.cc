#include "statModifiers.h"

#include "../../../lib/json.hpp"

using json = nlohmann::json;

StatModifiers::StatModifiers(const json& mods) {
  for (const auto& [key, value] : mods.items()) {
    if (value.contains("chance") && value.contains("value")) {
      chances[key] = value["chance"].get<float>();
      modifiers[key] = value["value"].get<int>();
    }
  }
}

int StatModifiers::getMod(const std::string& key) const {
  auto it = modifiers.find(key);
  return it != modifiers.end() ? it->second : 0;
}

float StatModifiers::getChance(const std::string& key) const {
  auto it = chances.find(key);
  return it != chances.end() ? it->second : 0.0f;
}

bool StatModifiers::hasMods() const {
  for (const auto& [key, value] : modifiers) {
    if (value != 0) {
      return true;
    }
  }
  return false;
}
