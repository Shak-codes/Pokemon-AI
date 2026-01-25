#ifndef __BIND__
#define __BIND__

#include <map>
#include <random>

#include "../../../lib/json.hpp"

using json = nlohmann::json;

/*
  This class defines the structure for how the bind effect works.
  Bind keeps an opponent unable to perform any actions whatsoever.
  The class stores a probability map called {prob}, which holds
  the probability for the number of turns the effect will last.
*/
class Bind {
  std::map<int, float> prob{};

 public:
  Bind(const json& effects);
  bool hasEffect() const;
  const std::map<int, float>& getProb() const;
  int selectDuration(std::mt19937& rng) const;
};

#endif