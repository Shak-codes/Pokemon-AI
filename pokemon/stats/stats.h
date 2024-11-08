#ifndef __STATS__
#define __STATS__

#include <string>

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
  int getHealth() const;
  int getAttack() const;
  int getDefense() const;
  int getSpecial() const;
  int getSpeed() const;
};

#endif