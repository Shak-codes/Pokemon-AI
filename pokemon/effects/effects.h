#ifndef __EFFECT__
#define __EFFECT__

#include <string>

#include "../../lib/json.hpp"
#include "../constants/enums.h"
#include "bind/bind.h"
#include "charge/charge.h"
#include "drain/drain.h"
#include "field/field.h"
#include "fixed/fixed.h"
#include "healing/healing.h"
#include "locked/locked.h"
#include "multistrike/multristrike.h"
#include "recoil/recoil.h"
#include "special/special.h"
#include "statModifiers/statModifiers.h"
#include "status/status.h"

using json = nlohmann::json;

class Effects {
  Bind bind;
  Charge charge;
  Drain drain;
  Fixed fixed;
  Field field;
  Locked locked;
  Healing healing;
  Multistrike multistrike;
  Recoil recoil;
  Special special;
  StatModifiers oppStats;
  StatModifiers userStats;
  Status userStatus;
  Status oppStatus;

  float flinch{0.0f};
  float critical{0.0f};
  bool effect{false};
  bool semiInvulnerable{false};
  int recharge{0};
  int priority{0};

 public:
  Effects(std::string move, const json& effects);
  bool isBind() const;
  bool isCharge() const;
  bool isDrain() const;
  bool isFixed() const;
  bool isLocked() const;
  bool isHealing() const;
  bool isMultistrike() const;
  bool isRecoil() const;
  bool isSpecial() const;
  bool affectsUserStatus() const;
  bool affectsOpponentStatus() const;
  bool affectsUserStats() const;
  bool affectsOpponentStats() const;
  bool isFlinch() const;
  bool isCritical() const;
  bool isSemiInvulnerable() const;
  bool isRecharge() const;
  bool isField() const;
  bool isPriority() const;

  std::string getSpecial() const;

  bool hasEffect() const;
  bool hasCat2Effect() const;
};

#endif