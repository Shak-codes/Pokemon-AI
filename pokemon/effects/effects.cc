#include "effects.h"

#include <string>

#include "../../lib/json.hpp"
#include "statModifiers/statModifiers.h"
#include "status/status.h"

using json = nlohmann::json;

Effects::Effects(std::string move, const json& effects)
    : userStatus(effects.contains("status") &&
                         effects["status"].contains("user")
                     ? Status(effects["status"]["user"])
                     : Status()),
      oppStatus(effects.contains("status") &&
                        effects["status"].contains("opponent")
                    ? Status(effects["status"]["opponent"])
                    : Status()),
      userStats(effects.contains("statMods") &&
                        effects["statMods"].contains("user")
                    ? StatModifiers(effects["statMods"]["user"])
                    : StatModifiers()),
      oppStats(effects.contains("statMods") &&
                       effects["statMods"].contains("opponent")
                   ? StatModifiers(effects["statMods"]["opponent"])
                   : StatModifiers()),
      special(move, effects) {}

bool Effects::affectsUserStatus() const {
  return userStatus.hasStatusEffects();
}
bool Effects::affectsOpponentStatus() const {
  return oppStatus.hasStatusEffects();
}
bool Effects::affectsUserStats() const { return userStats.hasMods(); }
bool Effects::affectsOpponentStats() const { return oppStats.hasMods(); }
bool Effects::isSpecial() const { return special.hasSpecialEffect(); }
std::string Effects::getSpecial() const { return special.getSpecialEffect(); }
