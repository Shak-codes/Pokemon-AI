#ifndef __EFFECT__
#define __EFFECT__

#include <string>

#include "../../lib/json.hpp"
#include "../constants/enums.h"
#include "bind/bind.h"
#include "charge/charge.h"
#include "drain/drain.h"
#include "fixed/fixed.h"
#include "healing/healing.h"
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
  Healing healing;
  Multistrike multistrike;
  Recoil recoil;
  Special special;
  StatModifiers oppStats;
  StatModifiers userStats;
  Status userStatus;
  Status oppStatus;

 public:
  Effects(std::string move, const json& effects);
  bool isBind() const;
  bool isCharge() const;
  bool isDrain() const;
  bool isFixed() const;
  bool isHealing() const;
  bool isMultistrike() const;
  bool isRecoil() const;
  bool isSpecial() const;
  bool affectsUserStatus() const;
  bool affectsOpponentStatus() const;
  bool affectsUserStats() const;
  bool affectsOpponentStats() const;
  std::string getSpecial() const;
};

#endif