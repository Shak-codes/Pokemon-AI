#include "effects.h"

#include <string>

#include "../../lib/json.hpp"
#include "statModifiers/statModifiers.h"
#include "status/status.h"

using json = nlohmann::json;

Effects::Effects(std::string move, const json& effects)
    : bind(effects),
      charge(effects),
      drain(effects),
      fixed(effects),
      healing(effects),
      multistrike(effects),
      recoil(effects),
      special(effects),

      userStatus(effects.contains("status") &&
                         effects["status"].contains("user")
                     ? Status(effects["status"]["user"])
                     : Status()),
      oppStatus(effects.contains("status") &&
                        effects["status"].contains("opponent")
                    ? Status(effects["status"]["opponent"])
                    : Status()),
      userStats(
          effects.contains("statMods")
              ? StatModifiers(effects["statMods"].value("user", json::object()))
              : StatModifiers({})),

      oppStats(effects.contains("statMods")
                   ? StatModifiers(
                         effects["statMods"].value("opponent", json::object()))
                   : StatModifiers({})) {}

bool Effects::isBind() const { return bind.hasEffect(); }
bool Effects::isCharge() const { return charge.hasEffect(); }
bool Effects::isDrain() const { return drain.hasEffect(); }
bool Effects::isFixed() const { return fixed.hasEffect(); }
bool Effects::isHealing() const { return healing.hasEffect(); }
bool Effects::isMultistrike() const { return multistrike.hasEffect(); }
bool Effects::isRecoil() const { return recoil.hasEffect(); }
bool Effects::isSpecial() const { return special.hasEffect(); }
bool Effects::affectsUserStats() const { return userStats.hasEffect(); }
bool Effects::affectsOpponentStats() const { return oppStats.hasEffect(); }
bool Effects::affectsUserStatus() const { return userStatus.hasEffect(); }
bool Effects::affectsOpponentStatus() const { return oppStatus.hasEffect(); }

std::string Effects::getSpecial() const { return special.getSpecialEffect(); }
