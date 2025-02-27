#ifndef FIXED
#define FIXED

#include "../../../../lib/json.hpp"

using json = nlohmann::json;

class Fixed {
 private:
  enum class DamageVariant { NONE, OPP_HP, USER_LEVEL, CONSTANT };
  DamageVariant variant{DamageVariant::NONE};
  float value{0.0f};

 public:
  Fixed(const json& effects);
  DamageVariant getVariant();
  float getValue() const;
  bool hasEffect() const;
};

#endif