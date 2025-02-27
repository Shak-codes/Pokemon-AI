#ifndef RECOIL_H
#define RECOIL_H

#include "../../../lib/json.hpp"

using json = nlohmann::json;

class Recoil {
 private:
  enum class RecoilWhen { ALWAYS, ON_MISS };
  enum class RecoilType { CONSTANT, PERCENTAGE, DAMAGE_DEALT };

  float damage{0.0f};
  RecoilWhen recoilWhen{RecoilWhen::ALWAYS};
  RecoilType recoilType{RecoilType::CONSTANT};

 public:
  Recoil() = default;
  Recoil(const json& recoilData);

  float getDamage() const;
  RecoilType getRecoilType() const;

  bool hasRecoil() const;
};

#endif