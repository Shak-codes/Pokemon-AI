#include "effects.h"

#include <string>

#include "../../lib/json.hpp"
#include "statModifiers/statModifiers.h"
#include "status/status.h"

using json = nlohmann::json;

Effects::Effects(const json& effects) {
  const json& statusEffects = effects["status"];
  const json& statMods = effects["statMods"];
  this->userStatus =
      statusEffects.contains("user") ? Status(statusEffects["user"]) : Status();
  this->oppStatus = statusEffects.contains("target")
                        ? Status(statusEffects["opponent"])
                        : Status();
  this->UserStatMods = statMods.contains("user")
                           ? StatModifiers(statMods["user"])
                           : StatModifiers();
  this->OppStatMods = statMods.contains("opponent")
                          ? StatModifiers(statMods["opponent"])
                          : StatModifiers();
};