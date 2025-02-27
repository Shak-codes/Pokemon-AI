#include "recoil.h"

#include "../../../lib/json.hpp"
using json = nlohmann::json;

Recoil::Recoil(const json& effects) {
  if (!effects.contains("recoil")) {
    return;
  }

  const json& recoilData = effects["recoil"];

  std::string recoilTypeStr = recoilData.value("type", "constant");
  std::string whenStr = recoilData.value("when", "always");
  damage = recoilData.value("value", 0.0f);
  std::string typeStr = recoilData.value("type", "standard");

  if (recoilTypeStr == "percentage")
    recoilType = RecoilType::PERCENTAGE;
  else if (recoilTypeStr == "damageDealt")
    recoilType = RecoilType::DAMAGE_DEALT;
  if (whenStr == "onMiss") recoilWhen = RecoilWhen::ON_MISS;
}

float Recoil::getDamage() const { return damage; }

Recoil::RecoilType Recoil::getRecoilType() const { return recoilType; }

bool Recoil::hasRecoil() const { return damage > 0.0f; }