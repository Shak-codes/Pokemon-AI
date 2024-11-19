#ifndef SPECIAL
#define SPECIAL

#include "../../../lib/json.hpp"
#include "fixed/fixed.h"
#include "multistrike/multristrike.h"
using json = nlohmann::json;

class Special {
 private:
  Multistrike multistrike;
  Fixed fixed;
  float recoil;
  bool alwaysHit;
  bool chargeMove;
  bool drain;
  bool ohko;
  bool bind;

 public:
  Special() = default;
  Special(const json& effects);
};

#endif