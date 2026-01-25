#ifndef __CHARGE__
#define __CHARGE__

#include <map>
#include <random>

#include "../../../lib/json.hpp"

using json = nlohmann::json;

/*
  This class defines the structure for how the charge effect works.
  Charge keeps a user unable to perform any actions whatsoever
  until the charge ends. The mapping stores the number of turns
  the move charges for and the probability it will take that many
  turns to complete charging.
*/
class Charge {
  std::map<int, float> prob{};

 public:
  Charge(const json& effects);
  bool hasEffect() const;
  const std::map<int, float>& getProb() const;
  int selectChargeTurns(std::mt19937& rng) const;
};

#endif