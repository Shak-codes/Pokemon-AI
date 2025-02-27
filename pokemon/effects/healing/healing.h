#ifndef __HEALING__
#define __HEALING__

#include "../../../lib/json.hpp"

using json = nlohmann::json;

class Healing {
  float value{0.0f};
  enum class HealingTypes { NONE, HEALTH, DAMAGE };
  HealingTypes type{HealingTypes::NONE};

 public:
  Healing(const json& effects);
  float getValue() const;
  bool hasEffect() const;
};

#endif