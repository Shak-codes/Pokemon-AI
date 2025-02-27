#ifndef __STATUS__
#define __STATUS__

#include <map>

#include "../../../lib/json.hpp"
using json = nlohmann::json;

class Status {
 private:
  std::map<std::string, float> statusEffects{};

 public:
  Status(const json& effects);
  std::map<std::string, float> getStatusEffect() const;
  bool hasEffect() const;
};

#endif
