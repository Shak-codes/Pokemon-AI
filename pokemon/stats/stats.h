#ifndef __STATS__
#define __STATS__

#include <string>
#include <unordered_map>

#include "../../lib/json.hpp"
#include "mods/mods.h"

using json = nlohmann::json;

struct IVS {
  int health = 8;
  int attack = 9;
  int special = 8;
  int defense = 8;
  int speed = 8;
};

class Stats {
  int level;
  int health;
  int attack;
  int defense;
  int special;
  int speed;
  Mods mods;
  IVS ivs;
  int evs = 0;

 public:
  Stats(const json& baseStats, int level);

  // Get base stats (unmodified by stat stages)
  int getHealth() const;
  int getAttack() const;
  int getDefense() const;
  int getSpecial() const;
  int getSpeed() const;
  int getLevel() const;

  // Get modified stats
  int getModifiedAttack() const;
  int getModifiedDefense() const;
  int getModifiedSpecial() const;
  int getModifiedSpeed() const;

  // Access to stat stage modifiers
  Mods& getMods();
  const Mods& getMods() const;
  void resetMods();

  // Get all base stats as a map
  std::unordered_map<std::string, int> getStats() const;
};

#endif