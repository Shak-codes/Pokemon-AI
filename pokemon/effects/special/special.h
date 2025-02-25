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
  std::vector<std::string> chargeFlags{"none", "bide", "other"};

  std::vector<std::string> copyFlags{"none", "mirrorMove", "mimic"};
  std::vector<std::string> customFlags{"psywave",   "rage",       "transform",
                                       "disable",   "conversion", "counter",
                                       "metronome", "dreamEater"};

  std::vector<std::string> multistrikeFlags{
      "none",        "doubleSlap", "cometPunch", "furyAttack", "pinMissile",
      "spikeCannon", "barrage",    "boneClub",   "twineedle",  "doubleKick"};

  std::vector<std::string> recoilFlags{"none", "takeDown", "doubleEdge",
                                       "submission"};

  std::vector<std::string> lockedFlags{"none", "rage", "thrash", "petalDance"};

  std::vector<std::string> lingerFlags{"none", "fireSpin", "wrap", "clamp",
                                       "bind"};

  std::vector<std::string> alwaysHitFlags{"none", "swift"};

  std::vector<std::string> drainingFlags{"none", "absorb", "megaDrain",
                                         "leechLife"};

  std::vector<std::string> ohkoFlags{"none", "fissure", "guillotine",
                                     "hornDrill"};

  std::vector<std::string> semiInvulnerableFlags{"none", "fly", "dig"};

  std::vector<std::string> forceSwapFlags{"none", "roar", "whirlwind"};

  std::vector<std::string> rechargeFlags{"none", "hyperBeam"};

  std::vector<std::vector<std::string>> allFlags{
      chargeFlags,   copyFlags,   customFlags,           multistrikeFlags,
      recoilFlags,   lockedFlags, lingerFlags,           alwaysHitFlags,
      drainingFlags, ohkoFlags,   semiInvulnerableFlags, forceSwapFlags,
      rechargeFlags};

  bool isSpecial{false};

  std::string specialEffect{"N/A"};

 public:
  Special(const json& moveData);
  std::string getSpecialEffect() const;
  bool hasSpecialEffect() const;
};

#endif