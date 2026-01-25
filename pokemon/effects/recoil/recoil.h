#ifndef RECOIL_H
#define RECOIL_H

#include <cmath>

#include "../../../lib/json.hpp"

using json = nlohmann::json;

/*
  This class defines the structure for how the Recoil effect works.
  Recoil moves deal a certain amount of damage to the user.
*/
class Recoil {
 private:
  enum class RecoilWhen { NONE, ALWAYS, ON_MISS };
  enum class RecoilType { NONE, CONSTANT, PERCENTAGE, DAMAGE_DEALT };

  float damage{0.0f};
  RecoilWhen recoilWhen{RecoilWhen::NONE};
  RecoilType recoilType{RecoilType::NONE};

 public:
  Recoil() = default;
  Recoil(const json& recoilData);

  float getDamage() const;
  RecoilType getRecoilType() const;
  bool triggersOnMiss() const;
  int calculateRecoil(int damageDealt, int userMaxHP) const;

  bool hasEffect() const;
};

#endif