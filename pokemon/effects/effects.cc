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
      field(effects),
      locked(effects),
      healing(effects),
      multistrike(effects),
      recoil(effects),
      special(effects),

      userStatus(effects.contains("status")
                     ? Status(effects["status"].value("user", json::object()))
                     : Status({})),
      oppStatus(effects.contains("status") ? Status(effects["status"].value(
                                                 "opponent", json::object()))
                                           : Status({})),

      userStats(
          effects.contains("statMods")
              ? StatModifiers(effects["statMods"].value("user", json::object()))
              : StatModifiers({})),
      oppStats(effects.contains("statMods")
                   ? StatModifiers(
                         effects["statMods"].value("opponent", json::object()))
                   : StatModifiers({})),

      flinch(effects.value("flinch", 0.0f)),
      critical(effects.value("critical", 0.0f)),
      semiInvulnerable(effects.value("semi-invulnerable", false)),
      recharge(effects.value("recharge", 0)),
      priority(effects.value("priority", 0)) {
  this->effect = isBind() || isCharge() || isDrain() || isFixed() ||
                 isHealing() || isMultistrike() || isRecoil() || isSpecial() ||
                 affectsUserStatus() || affectsOpponentStatus() ||
                 affectsUserStats() || affectsOpponentStats();
}

bool Effects::isBind() const { return bind.hasEffect(); }
bool Effects::isCharge() const { return charge.hasEffect(); }
bool Effects::isDrain() const { return drain.hasEffect(); }
bool Effects::isFixed() const { return fixed.hasEffect(); }
bool Effects::isLocked() const { return locked.hasEffect(); }
bool Effects::isHealing() const { return healing.hasEffect(); }
bool Effects::isMultistrike() const { return multistrike.hasEffect(); }
bool Effects::isRecoil() const { return recoil.hasEffect(); }
bool Effects::isSpecial() const { return special.hasEffect(); }
bool Effects::affectsUserStats() const { return userStats.hasEffect(); }
bool Effects::affectsOpponentStats() const { return oppStats.hasEffect(); }
bool Effects::affectsUserStatus() const { return userStatus.hasEffect(); }
bool Effects::affectsOpponentStatus() const { return oppStatus.hasEffect(); }
bool Effects::isFlinch() const { return flinch > 0.0f; }
bool Effects::isCritical() const { return critical > 0.0f; }
bool Effects::isSemiInvulnerable() const { return semiInvulnerable; }
bool Effects::isRecharge() const { return recharge > 0; }
bool Effects::isField() const { return field.hasEffect(); }
bool Effects::isPriority() const { return priority != 0; }

std::string Effects::getSpecial() const { return special.getSpecialEffect(); }

bool Effects::hasEffect() const { return effect; }
bool Effects::hasCat2Effect() const {
  return userStats.hasEffect() || oppStats.hasEffect();
}
