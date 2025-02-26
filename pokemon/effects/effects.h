#ifndef __EFFECT__
#define __EFFECT__

#include <string>

#include "../../lib/json.hpp"
#include "../constants/enums.h"
#include "special/special.h"
#include "statModifiers/statModifiers.h"
#include "status/status.h"

using json = nlohmann::json;

class Effects {
  Status userStatus;
  Status oppStatus;
  Special special;
  StatModifiers oppStats;
  StatModifiers userStats;

 public:
  Effects(std::string move, const json& effects);
  bool affectsUserStatus() const;
  bool affectsOpponentStatus() const;
  bool affectsUserStats() const;
  bool affectsOpponentStats() const;
  bool isSpecial() const;
  std::string getSpecial() const;
};

#endif