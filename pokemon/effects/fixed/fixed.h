#ifndef FIXED
#define FIXED

#include "../../../../lib/json.hpp"

using json = nlohmann::json;

class Fixed {
 private:
  enum DamageVariant { NONE, OPP_HP, USER_LEVEL, CONSTANT };
  DamageVariant variant{NONE};
  float value{0.0f};
  bool fixed{false};

 public:
  Fixed(const json& effects);
  DamageVariant getVariant();
  float getValue() const;
  bool isFixed() const;
};

#endif