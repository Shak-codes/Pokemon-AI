#include "recoil.h"

#include "../../../../lib/json.hpp"

using json = nlohmann::json;

Recoil::Recoil(const json& data) {
  std::string damageTypeStr = data["value"].value("type", "constant");
  damage = data["value"].value("value", 0.0f);
  std::string typeStr = data.value("type", "standard");
  if (damageTypeStr == "percentage") damageType = PERCENTAGE;
  if (typeStr == "onMiss") recoilType = MISS_ONLY;
}

float Recoil::getDamage() const { return damage; }

Recoil::RecoilType Recoil::getRecoilType() const { return recoilType; }

bool Recoil::hasRecoil() const { return damage > 0.0f; }