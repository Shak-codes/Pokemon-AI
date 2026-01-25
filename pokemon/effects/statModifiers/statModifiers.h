#ifndef STATMODIFIERS
#define STATMODIFIERS

#include <map>
#include <random>
#include <string>

#include "../../../lib/json.hpp"
using json = nlohmann::json;

/*
 * This class defines the structure for how the StatModifiers effect
 * works. Moves with this effect alter the user/opponent's stats
 * in some form.
 */
class StatModifiers {
 private:
  std::map<std::string, std::pair<int, float>> mods{};

 public:
  StatModifiers(const json& mods);

  std::pair<int, float> getMod(const std::string& key) const;
  const std::map<std::string, std::pair<int, float>>& getAllMods() const;
  bool hasEffect() const;

  bool apply(class Mods& targetMods, std::mt19937& rng) const;
};

#endif
