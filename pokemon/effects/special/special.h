#ifndef SPECIAL
#define SPECIAL

#include <string>

#include "../../../lib/json.hpp"
#include "fixed/fixed.h"
#include "multistrike/multristrike.h"
#include "recoil/recoil.h"
using json = nlohmann::json;

class Special {
 private:
  enum class ChargeMoves { NONE, BIDE, OTHER };
  enum class CopyMoves { NONE, MIRROR_MOVE, MIMIC };
  enum class CustomEffectMoves {
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
  enum class MultistrikeMoves {
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
  enum class RecoilMoves { NONE, TAKE_DOWN, DOUBLE_EDGE, SUBMISSION };
  enum class LockedMoves { NONE, RAGE, THRASH, PETAL_DANCE };
  enum class LingerMoves { NONE, FIRE_SPIN, WRAP, CLAMP, BIND };
  enum class AlwaysHitMoves { NONE, SWIFT };
  enum class DrainingMoves { NONE, ABSORB, MEGA_DRAIN, LEECH_LIFE };
  enum class OHKOMoves { NONE, FISSURE, GUILLOTINE, HORN_DRILL };
  enum class SemiInvulnerableMoves { NONE, FLY, DIG };
  enum class ForceSwapMoves { NONE, ROAR, WHIRLWIND };
  enum class RechargeMove { NONE, HYPER_BEAM };

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
  Special(std::string move, const json& effects);
  std::string getSpecialEffect() const;
  bool hasSpecialEffect() const;
};

#endif