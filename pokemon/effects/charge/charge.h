#ifndef __CHARGE__
#define __CHARGE__

#include "../../../lib/json.hpp"

using json = nlohmann::json;

class Charge {
  std::map<int, float> prob{};

 public:
  Charge(const json& effects);
  bool hasEffect() const;
  const std::map<int, float>& getProb() const;
};

#endif