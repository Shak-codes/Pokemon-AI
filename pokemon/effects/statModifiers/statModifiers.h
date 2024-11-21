#ifndef STATMODIFIERS
#define STATMODIFIERS

#include <map>

#include "../../../lib/json.hpp"
using json = nlohmann::json;

class StatModifiers {
 private:
  std::map<std::string, int> modifiers;
  std::map<std::string, float> chances;

 public:
  StatModifiers(const json& mods);

  int getMod(const std::string& key) const;
  float getChance(const std::string& key) const;
  bool hasMods() const;
};

#endif
