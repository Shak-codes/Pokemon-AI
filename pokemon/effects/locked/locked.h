#ifndef __LOCKED__
#define __LOCKED__

#include <map>
#include <random>

#include "../../../lib/json.hpp"

using json = nlohmann::json;

/*
  This class defines the structure for how the Locked effect works.
  When using a move with the Locked effect, the user must continously
  use that move for the next few turns before they can select a different
  move.
*/
class Locked {
 private:
  std::map<int, float> prob{};

 public:
  Locked(const json& effects);
  const std::map<int, float>& getProb() const;
  bool hasEffect() const;
  int selectDuration(std::mt19937& rng) const;
};

#endif
