#ifndef FIXED
#define FIXED

#include "../../../../lib/json.hpp"

using json = nlohmann::json;

class Fixed {
 private:
  enum DamageVariant { OPP_HP, USER_LEVEL, CONSTANT };
  DamageVariant variant;
  float value;

 public:
  Fixed(const json& damage);
  DamageVariant getVariant();
  float getValue() const;
};

#endif