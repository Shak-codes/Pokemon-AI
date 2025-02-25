#ifndef RECOIL_H
#define RECOIL_H

#include "../../../../lib/json.hpp"

using json = nlohmann::json;

class Recoil {
 private:
  enum RecoilType { STANDARD, MISS_ONLY };
  enum DamageType { CONSTANT, PERCENTAGE };

  float damage{0.0f};
  DamageType damageType{CONSTANT};
  RecoilType recoilType{STANDARD};

 public:
  Recoil() = default;
  Recoil(const json& recoilData);

  float getDamage() const;
  RecoilType getRecoilType() const;

  bool hasRecoil() const;
};

#endif