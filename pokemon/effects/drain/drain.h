#ifndef __DRAIN__
#define __DRAIN__

#include <cmath>

#include "../../../lib/json.hpp"

using json = nlohmann::json;

/*
  This class defines the structure for how the Drain effect works.
  Drain removes a specific percentage of HP from the enemy at the
  end of every turn.
*/
class Drain {
  float value{0.0f};

 public:
  Drain(const json& effects);
  bool hasEffect() const;
  float getValue() const;
  int calculateHealing(int damageDealt) const;
};

#endif