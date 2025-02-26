#ifndef __STATUS__
#define __STATUS__

#include <map>
#include <string>

#include "../../../lib/json.hpp"
using json = nlohmann::json;

class Status {
 private:
  std::map<std::string, float> statusEffects;

 public:
  Status() = default;
  Status(const json& status);
  float getStatusEffect(const std::string& key) const;
  bool hasStatusEffects() const;
};

#endif
