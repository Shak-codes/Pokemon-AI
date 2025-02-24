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
  // Special specialEffects;
  StatModifiers OppStatMods;
  StatModifiers UserStatMods;

 public:
  Effects(const json& effects);
};

#endif