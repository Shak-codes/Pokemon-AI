#ifndef __HEALING__
#define __HEALING__

#include <cmath>

#include "../../../lib/json.hpp"

using json = nlohmann::json;

/*
  This class defines the structure for how the Healing effect works.
  Moves with this effect heal the user in some form.
*/
class Healing {
  float value{0.0f};
  enum class HealingTypes { NONE, HEALTH, DAMAGE };
  HealingTypes type{HealingTypes::NONE};

 public:
  Healing(const json& effects);
  float getValue() const;
  bool hasEffect() const;
  int calculateHealing(int maxHP, int damageDealt = 0) const;
};

#endif