#include "stats.h"

#include <cmath>
#include <string>

using json = nlohmann::json;

Stats::Stats(const json& baseStats, int lvl) : level(lvl) {
  int baseHP = std::stoi(baseStats["hp"].get<std::string>());
  int baseAttack = std::stoi(baseStats["atk"].get<std::string>());
  int baseDefense = std::stoi(baseStats["def"].get<std::string>());
  int baseSpeed = std::stoi(baseStats["spe"].get<std::string>());
  int baseSpecial = std::stoi(baseStats["spd"].get<std::string>());

  health = (((baseHP + ivs.health) * 2) * level) / 100 + level + 10;
  attack = (((baseAttack + ivs.attack) * 2) * level) / 100 + 5;
  defense = (((baseDefense + ivs.defense) * 2) * level) / 100 + 5;
  speed = (((baseSpeed + ivs.speed) * 2) * level) / 100 + 5;
  special = (((baseSpecial + ivs.special) * 2) * level) / 100 + 5;
}

int Stats::getHealth() const { return health; }
int Stats::getAttack() const { return attack; }
int Stats::getDefense() const { return defense; }
int Stats::getSpecial() const { return special; }
int Stats::getSpeed() const { return speed; }
int Stats::getLevel() const { return level; }

int Stats::getModifiedAttack() const {
  return mods.applyToStat(attack, "attack");
}

int Stats::getModifiedDefense() const {
  return mods.applyToStat(defense, "defense");
}

int Stats::getModifiedSpecial() const {
  return mods.applyToStat(special, "special");
}

int Stats::getModifiedSpeed() const {
  return mods.applyToStat(speed, "speed");
}

Mods& Stats::getMods() { return mods; }

const Mods& Stats::getMods() const { return mods; }

void Stats::resetMods() { mods.reset(); }

std::unordered_map<std::string, int> Stats::getStats() const {
  return {{"health", health},
          {"attack", attack},
          {"defense", defense},
          {"special", special},
          {"speed", speed}};
}
