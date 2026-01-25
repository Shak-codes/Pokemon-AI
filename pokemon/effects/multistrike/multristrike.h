#ifndef MULTISTRIKE
#define MULTISTRIKE

#include <map>
#include <random>

#include "../../../lib/json.hpp"

using json = nlohmann::json;

/*
  This class defines the structure for how the Multistrike effect works.
  Multistrike moves hit multiple times in one turn. As such, damage is
  calculated somewhat differently for Multistrike moves.
*/
class Multistrike {
 private:
  std::map<int, float> prob{};

 public:
  Multistrike(const json& effects);
  const std::map<int, float>& getProb() const;
  bool hasEffect() const;
  int selectHitCount(std::mt19937& rng) const;
};

#endif
