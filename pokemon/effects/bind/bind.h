#ifndef __BIND__
#define __BIND__

#include "../../../lib/json.hpp"

using json = nlohmann::json;

class Bind {
  std::map<int, float> prob{};

 public:
  Bind(const json& effects);
  bool hasEffect() const;
  const std::map<int, float>& getProb() const;
};

#endif