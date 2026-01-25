#ifndef FIXED
#define FIXED

#include <cmath>

#include "../../../lib/json.hpp"

using json = nlohmann::json;

/*
  This class defines the structure for how the Fixed effect works.
  Moves that have the fixed effect deal an exact number of damage
  every time.
*/
class Fixed {
 private:
  enum class DamageVariant { NONE, OPP_HP, USER_LEVEL, CONSTANT };
  DamageVariant variant{DamageVariant::NONE};
  float value{0.0f};

 public:
  Fixed(const json& effects);
  DamageVariant getVariant() const;
  float getValue() const;
  bool hasEffect() const;
  int calculateDamage(int userLevel, int opponentCurrentHP) const;
};

#endif