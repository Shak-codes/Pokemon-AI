#include "special.h"

#include "../../../lib/json.hpp"

using json = nlohmann::json;

Special::Special(const json& effects) {
  const json& status = effects["status"];
  this->userStatus = status.contains("user") ? status["user"] : Status();
  this->oppStatus = status.contains("target") ? status["target"] : Status();
}

std::string Special::getSpecialEffect() const {
  if (alwaysHit) return "alwaysHit";
  if (drain) return "drain";
  if (ohko) return "ohko";
  if (semiInv) return "semiInv";
  if (forceSwap) return "forceSwap";
  if (rage) return "rage";
  if (transform) return "transform";
  if (disable) return "disable";
  if (conversion) return "conversion";
  if (counter) return "counter";
  if (haze) return "haze";
  if (recharge) return "recharge";
  if (metronome) return "metronome";

  switch (linger) {
    case LEECH_SEED:
      return "leechSeed";
    case WRAP:
      return "wrap";
    case BIND:
      return "bind";
    default:
      break;
  }

  switch (chargeMove) {
    case BIDE:
      return "bide";
    case OTHER:
      return "otherChargeMove";
    default:
      break;
  }

  switch (copy) {
    case MIRROR_MOVE:
      return "mirrorMove";
    case MIMIC:
      return "mimic";
    default:
      break;
  }

  return "";
}
