#ifndef SPECIAL
#define SPECIAL

#include "../../../lib/json.hpp"
#include "fixed/fixed.h"
#include "multistrike/multristrike.h"
#include "recoil/recoil.h"
using json = nlohmann::json;

class Special {
 private:
  enum ChargeMoves { NONE, BIDE, OTHER };
  enum CopyMoves { NONE, MIRROR_MOVE, MIMIC };
  enum CustomEffectMoves {
    NONE,
    PSYWAVE,
    RAGE,
    TRANSFORM,
    DISABLE,
    CONVERSION,
    COUNTER,
    METRONOME,
    DREAM_EATER
  };
  enum MultistrikeMoves {
    NONE,
    DOUBLE_SLAP,
    COMET_PUNCH,
    FURY_ATTACK,
    PIN_MISSILE,
    SPIKE_CANNON,
    BARRAGE,
    BONE_CLUB,
    TWINEEDLE,
    DOUBLE_KICK
  };
  enum RecoilMoves { NONE, TAKE_DOWN, DOUBLE_EDGE, SUBMISSION };
  enum LockedMoves { NONE, RAGE, THRASH, PETAL_DANCE };
  enum LingerMoves { NONE, FIRE_SPIN, WRAP, CLAMP, BIND };
  enum AlwaysHitMoves { NONE, SWIFT };
  enum DrainingMoves { NONE, ABSORB, MEGA_DRAIN, LEECH_LIFE };
  enum OHKOMoves { NONE, FISSURE, GUILLOTINE, HORN_DRILL };
  enum SemiInvulnerableMoves { NONE, FLY, DIG };
  enum ForceSwapMoves { NONE, ROAR, WHIRLWIND };
  enum RechargeMove { NONE, HYPER_BEAM };

  Multistrike multistrike;
  Fixed fixed;
  Recoil recoil;
  std::vector<std::string> specialFlags = {
      "psywave",    "rage",    "transform", "disable",
      "conversion", "counter", "metronome", "dreamEater"};
  bool haze = false;  // Should be in stat change section

 public:
  Special() = default;
  Special(const json& effects);
  std::string getSpecialEffect() const;
};

#endif