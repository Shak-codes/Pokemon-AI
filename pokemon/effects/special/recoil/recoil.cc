#include "recoil.h"

#include "../../../../lib/json.hpp"

using json = nlohmann::json;

Recoil::Recoil(const json& effects) {
  std::string damageTypeStr = effects["value"].value("type", "constant");
  damage = effects["value"].value("value", 0.0f);
  std::string typeStr = effects.value("type", "standard");
  if (damageTypeStr == "percentage") damageType = PERCENTAGE;
  if (typeStr == "onMiss") recoilType = MISS_ONLY;
}

float Recoil::getDamage() const { return damage; }

Recoil::RecoilType Recoil::getRecoilType() const { return recoilType; }

bool Recoil::hasRecoil() const { return damage > 0.0f; }