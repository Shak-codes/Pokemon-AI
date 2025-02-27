#ifndef STATMODIFIERS
#define STATMODIFIERS

#include <map>

#include "../../../lib/json.hpp"
using json = nlohmann::json;

class StatModifiers {
 private:
  std::map<std::string, std::pair<int, float>> mods{};

 public:
  StatModifiers(const json& mods);

  std::pair<int, float> getMod(const std::string& key) const;
  bool hasEffect() const;
};

#endif
