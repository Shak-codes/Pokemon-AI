#ifndef __DRAIN__
#define __DRAIN__

#include "../../../lib/json.hpp"

using json = nlohmann::json;

class Drain {
  float value{0.0f};

 public:
  Drain(const json& effects);
  bool hasEffect() const;
  float getValue() const;
};

#endif