#ifndef SPECIAL
#define SPECIAL

#include "../../../lib/json.hpp"
#include "fixed/fixed.h"
#include "multistrike/multristrike.h"
#include "recoil/recoil.h"
using json = nlohmann::json;

class Special {
 private:
  enum LingeringEffect { NONE, LEECH_SEED, WRAP, BIND };
  enum ChargeMove { NONE, BIDE, OTHER };
  enum CopyMove { NONE, MIRROR_MOVE, MIMIC };
  Multistrike multistrike;
  Fixed fixed;
  Recoil recoil;
  LingeringEffect linger = NONE;
  ChargeMove chargeMove = ChargeMove::NONE;
  CopyMove copy = CopyMove::NONE;
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

 public:
  Special() = default;
  Special(const json& effects);
  std::string getSpecialEffect() const;
};

#endif