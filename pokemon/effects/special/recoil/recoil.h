#ifndef RECOIL_H
#define RECOIL_H

#include "../../../../lib/json.hpp"

using json = nlohmann::json;

class Recoil {
 private:
  enum RecoilWhen { ALWAYS, ON_MISS };
  enum RecoilType { CONSTANT, PERCENTAGE, DAMAGE_DEALT };

  float damage{0.0f};
  RecoilWhen recoilWhen{ALWAYS};
  RecoilType recoilType{CONSTANT};

 public:
  Recoil() = default;
  Recoil(const json& recoilData);

  float getDamage() const;
  RecoilType getRecoilType() const;

  bool hasRecoil() const;
};

#endif