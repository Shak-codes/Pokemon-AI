#ifndef __LOCKED__
#define __LOCKED__

#include "../../../lib/json.hpp"

using json = nlohmann::json;

class Locked {
 private:
  std::map<int, float> prob{};

 public:
  Locked(const json& effects);
  const std::map<int, float>& getProb() const;
  bool hasEffect() const;
};

#endif
