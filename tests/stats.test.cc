#include "../pokemon/stats/stats.h"

#include <cassert>
#include <iostream>

#include "../lib/json.hpp"

using json = nlohmann::json;

int main() {
  json baseStats = {
      {"hp", "45"}, {"atk", "49"}, {"def", "49"}, {"spe", "45"}, {"spd", "65"}};

  int level = 50;
  Stats stats(baseStats, level);

  int expectedHealth = (((45 + 8) * 2 * level) / 100) + level + 10;
  int expectedAttack = (((49 + 9) * 2) * level) / 100 + 5;
  int expectedDefense = (((49 + 8) * 2 * level) / 100) + 5;
  int expectedSpeed = (((45 + 8) * 2 * level) / 100) + 5;
  int expectedSpecial = (((65 + 8) * 2 * level) / 100) + 5;

  assert(stats.getHealth() == expectedHealth && "Health calculation failed");
  assert(stats.getAttack() == expectedAttack && "Attack calculation failed");
  assert(stats.getDefense() == expectedDefense && "Defense calculation failed");
  assert(stats.getSpeed() == expectedSpeed && "Speed calculation failed");
  assert(stats.getSpecial() == expectedSpecial && "Special calculation failed");

  std::cout << "All Stats tests passed!" << std::endl;
  return 0;
}
