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
  if (recoilTypeStr == "percentage")
    recoilType = RecoilType::PERCENTAGE;
  else if (recoilTypeStr == "damageDealt")
    recoilType = RecoilType::DAMAGE_DEALT;
  else
    recoilType = RecoilType::CONSTANT;

  if (whenStr == "onMiss")
    recoilWhen = RecoilWhen::ON_MISS;
  else
    recoilWhen = RecoilWhen::ALWAYS;
}

float Recoil::getDamage() const { return damage; }

Recoil::RecoilType Recoil::getRecoilType() const { return recoilType; }

bool Recoil::triggersOnMiss() const { return recoilWhen == RecoilWhen::ON_MISS; }

int Recoil::calculateRecoil(int damageDealt, int userMaxHP) const {
  if (!hasEffect() || userMaxHP <= 0) return 0;

  float rawRecoil = 0.0f;
  if (recoilType == RecoilType::CONSTANT) {
    rawRecoil = damage;
  } else if (recoilType == RecoilType::PERCENTAGE) {
    rawRecoil = static_cast<float>(userMaxHP) * damage;
  } else if (recoilType == RecoilType::DAMAGE_DEALT) {
    if (damageDealt <= 0) return 0;
    rawRecoil = static_cast<float>(damageDealt) * damage;
  }

  int recoil = static_cast<int>(std::floor(rawRecoil));
  return recoil < 0 ? 0 : recoil;
}

bool Recoil::hasEffect() const { return recoilType != RecoilType::NONE; }