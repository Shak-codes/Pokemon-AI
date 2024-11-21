#ifndef SPECIAL
#define SPECIAL

#include "../../../lib/json.hpp"
#include "fixed/fixed.h"
#include "multistrike/multristrike.h"
#include "recoil/recoil.h"
using json = nlohmann::json;

class Special {
 private:
  enum ChargeMove { NONE, BIDE, OTHER };
  enum CopyMove { NONE, MIRROR_MOVE, MIMIC };
  Multistrike multistrike;
  Fixed fixed;
  Recoil recoil;
  ChargeMove chargeMove = ChargeMove::NONE;
  CopyMove copy = CopyMove::NONE;
  bool linger = false;
  bool alwaysHit = false;
  bool drain = false;
  bool ohko = false;
  bool semiInv = false;
  bool forceSwap = false;
  bool rage = false;
  bool transform = false;
  bool disable = false;
  bool conversion = false;
  bool counter = false;
  bool haze = false;  // Should be in stat change section
  bool recharge = false;
  bool metronome = false;
  bool dreamEater = false;

 public:
  Special() = default;
  Special(const json& effects);
  std::string getSpecialEffect() const;
};

#endif