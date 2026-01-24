#include "../pokemon/stats/stats.h"

#include <cassert>
#include <cmath>
#include <iostream>

#include "../lib/json.hpp"

using json = nlohmann::json;

void testBaseStatCalculation() {
  std::cout << "Testing base stat calculation..." << std::endl;

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
  assert(stats.getLevel() == level && "Level should be stored correctly");

  std::cout << "  Base stat calculation tests passed!" << std::endl;
}

void testModifiedStatsAtStageZero() {
  std::cout << "Testing modified stats at stage 0..." << std::endl;

  json baseStats = {
      {"hp", "45"}, {"atk", "49"}, {"def", "49"}, {"spe", "45"}, {"spd", "65"}};

  Stats stats(baseStats, 50);

  // At stage 0, modified stats should equal base stats
  assert(stats.getModifiedAttack() == stats.getAttack() &&
         "Modified attack should equal base attack at stage 0");
  assert(stats.getModifiedDefense() == stats.getDefense() &&
         "Modified defense should equal base defense at stage 0");
  assert(stats.getModifiedSpecial() == stats.getSpecial() &&
         "Modified special should equal base special at stage 0");
  assert(stats.getModifiedSpeed() == stats.getSpeed() &&
         "Modified speed should equal base speed at stage 0");

  std::cout << "  Modified stats at stage 0 tests passed!" << std::endl;
}

void testModifiedStatsWithPositiveStages() {
  std::cout << "Testing modified stats with positive stages..." << std::endl;

  json baseStats = {
      {"hp", "100"}, {"atk", "100"}, {"def", "100"}, {"spe", "100"}, {"spd", "100"}};

  Stats stats(baseStats, 100);
  int baseAttack = stats.getAttack();

  // Stage +1: multiplier 1.5
  stats.getMods().modifyAttack(1);
  int expectedModified = static_cast<int>(std::floor(baseAttack * 1.5));
  assert(stats.getModifiedAttack() == expectedModified &&
         "Stage +1 should multiply attack by 1.5");

  // Stage +2: multiplier 2.0
  stats.getMods().modifyAttack(1);
  expectedModified = static_cast<int>(std::floor(baseAttack * 2.0));
  assert(stats.getModifiedAttack() == expectedModified &&
         "Stage +2 should multiply attack by 2.0");

  // Stage +6: multiplier 4.0
  stats.getMods().modifyAttack(4);
  expectedModified = static_cast<int>(std::floor(baseAttack * 4.0));
  // Clamp to 999 if needed
  if (expectedModified > 999) expectedModified = 999;
  assert(stats.getModifiedAttack() == expectedModified &&
         "Stage +6 should multiply attack by 4.0 (clamped to 999)");

  std::cout << "  Modified stats with positive stages tests passed!" << std::endl;
}

void testModifiedStatsWithNegativeStages() {
  std::cout << "Testing modified stats with negative stages..." << std::endl;

  json baseStats = {
      {"hp", "100"}, {"atk", "100"}, {"def", "100"}, {"spe", "100"}, {"spd", "100"}};

  Stats stats(baseStats, 100);
  int baseDefense = stats.getDefense();

  // Stage -1: multiplier 2/3
  stats.getMods().modifyDefense(-1);
  int expectedModified = static_cast<int>(std::floor(baseDefense * (2.0 / 3.0)));
  assert(stats.getModifiedDefense() == expectedModified &&
         "Stage -1 should multiply defense by 2/3");

  // Stage -2: multiplier 0.5
  stats.getMods().modifyDefense(-1);
  expectedModified = static_cast<int>(std::floor(baseDefense * 0.5));
  assert(stats.getModifiedDefense() == expectedModified &&
         "Stage -2 should multiply defense by 0.5");

  // Stage -6: multiplier 0.25
  stats.getMods().modifyDefense(-4);
  expectedModified = static_cast<int>(std::floor(baseDefense * 0.25));
  if (expectedModified < 1) expectedModified = 1;
  assert(stats.getModifiedDefense() == expectedModified &&
         "Stage -6 should multiply defense by 0.25");

  std::cout << "  Modified stats with negative stages tests passed!" << std::endl;
}

void testGetMods() {
  std::cout << "Testing getMods() access..." << std::endl;

  json baseStats = {
      {"hp", "80"}, {"atk", "80"}, {"def", "80"}, {"spe", "80"}, {"spd", "80"}};

  Stats stats(baseStats, 50);

  // Modify stats through getMods()
  stats.getMods().modifyAttack(2);
  stats.getMods().modifyDefense(-1);
  stats.getMods().modifySpecial(3);
  stats.getMods().modifySpeed(-2);

  // Verify stages were set
  assert(stats.getMods().getAttack() == 2 && "Attack stage should be +2");
  assert(stats.getMods().getDefense() == -1 && "Defense stage should be -1");
  assert(stats.getMods().getSpecial() == 3 && "Special stage should be +3");
  assert(stats.getMods().getSpeed() == -2 && "Speed stage should be -2");

  // Verify modified stats reflect the stages
  int baseAttack = stats.getAttack();
  int expectedModifiedAttack = static_cast<int>(std::floor(baseAttack * 2.0));
  assert(stats.getModifiedAttack() == expectedModifiedAttack &&
         "Modified attack should reflect +2 stage");

  std::cout << "  getMods() access tests passed!" << std::endl;
}

void testResetMods() {
  std::cout << "Testing resetMods()..." << std::endl;

  json baseStats = {
      {"hp", "80"}, {"atk", "80"}, {"def", "80"}, {"spe", "80"}, {"spd", "80"}};

  Stats stats(baseStats, 50);

  // Modify all stats
  stats.getMods().modifyAttack(3);
  stats.getMods().modifyDefense(-2);
  stats.getMods().modifySpecial(4);
  stats.getMods().modifySpeed(-3);
  stats.getMods().modifyAccuracy(2);
  stats.getMods().modifyEvasion(-1);

  // Reset all mods
  stats.resetMods();

  // Verify all stages are 0
  assert(stats.getMods().getAttack() == 0 && "Attack stage should be 0 after reset");
  assert(stats.getMods().getDefense() == 0 && "Defense stage should be 0 after reset");
  assert(stats.getMods().getSpecial() == 0 && "Special stage should be 0 after reset");
  assert(stats.getMods().getSpeed() == 0 && "Speed stage should be 0 after reset");
  assert(stats.getMods().getAccuracy() == 0 && "Accuracy stage should be 0 after reset");
  assert(stats.getMods().getEvasion() == 0 && "Evasion stage should be 0 after reset");

  // Verify modified stats equal base stats after reset
  assert(stats.getModifiedAttack() == stats.getAttack() &&
         "Modified attack should equal base after reset");
  assert(stats.getModifiedDefense() == stats.getDefense() &&
         "Modified defense should equal base after reset");

  std::cout << "  resetMods() tests passed!" << std::endl;
}

void testStatClamping() {
  std::cout << "Testing stat value clamping (1-999)..." << std::endl;

  // Create a Pokemon with high base stats to test 999 cap
  json highBaseStats = {
      {"hp", "255"}, {"atk", "255"}, {"def", "255"}, {"spe", "255"}, {"spd", "255"}};

  Stats stats(highBaseStats, 100);

  // At stage +6 (4x multiplier), high stats should cap at 999
  stats.getMods().modifyAttack(6);
  assert(stats.getModifiedAttack() <= 999 &&
         "Modified attack should not exceed 999");

  // Create a Pokemon with low base stats to test minimum 1
  json lowBaseStats = {
      {"hp", "10"}, {"atk", "5"}, {"def", "5"}, {"spe", "5"}, {"spd", "5"}};

  Stats lowStats(lowBaseStats, 5);

  // At stage -6 (0.25x multiplier), low stats should not go below 1
  lowStats.getMods().modifyDefense(-6);
  assert(lowStats.getModifiedDefense() >= 1 &&
         "Modified defense should not go below 1");

  std::cout << "  Stat value clamping tests passed!" << std::endl;
}

void testConstMods() {
  std::cout << "Testing const getMods()..." << std::endl;

  json baseStats = {
      {"hp", "80"}, {"atk", "80"}, {"def", "80"}, {"spe", "80"}, {"spd", "80"}};

  Stats stats(baseStats, 50);
  stats.getMods().modifyAttack(2);

  // Test const access
  const Stats& constStats = stats;
  assert(constStats.getMods().getAttack() == 2 &&
         "Const getMods should return correct stage");
  assert(constStats.getModifiedAttack() == stats.getModifiedAttack() &&
         "Const modified attack should work");

  std::cout << "  Const getMods() tests passed!" << std::endl;
}

void testGetStatsMap() {
  std::cout << "Testing getStats() map..." << std::endl;

  json baseStats = {
      {"hp", "45"}, {"atk", "49"}, {"def", "49"}, {"spe", "45"}, {"spd", "65"}};

  Stats stats(baseStats, 50);
  auto statsMap = stats.getStats();

  assert(statsMap["health"] == stats.getHealth() && "Map health should match");
  assert(statsMap["attack"] == stats.getAttack() && "Map attack should match");
  assert(statsMap["defense"] == stats.getDefense() && "Map defense should match");
  assert(statsMap["special"] == stats.getSpecial() && "Map special should match");
  assert(statsMap["speed"] == stats.getSpeed() && "Map speed should match");

  std::cout << "  getStats() map tests passed!" << std::endl;
}

void testDifferentLevels() {
  std::cout << "Testing stats at different levels..." << std::endl;

  json baseStats = {
      {"hp", "50"}, {"atk", "50"}, {"def", "50"}, {"spe", "50"}, {"spd", "50"}};

  Stats level1(baseStats, 1);
  Stats level50(baseStats, 50);
  Stats level100(baseStats, 100);

  // Stats should increase with level
  assert(level1.getAttack() < level50.getAttack() &&
         "Level 50 should have higher attack than level 1");
  assert(level50.getAttack() < level100.getAttack() &&
         "Level 100 should have higher attack than level 50");

  // Verify level storage
  assert(level1.getLevel() == 1 && "Level 1 should be stored");
  assert(level50.getLevel() == 50 && "Level 50 should be stored");
  assert(level100.getLevel() == 100 && "Level 100 should be stored");

  std::cout << "  Different levels tests passed!" << std::endl;
}

int main() {
  std::cout << "\n=== Stats Class Tests ===" << std::endl << std::endl;

  testBaseStatCalculation();
  testModifiedStatsAtStageZero();
  testModifiedStatsWithPositiveStages();
  testModifiedStatsWithNegativeStages();
  testGetMods();
  testResetMods();
  testStatClamping();
  testConstMods();
  testGetStatsMap();
  testDifferentLevels();

  std::cout << std::endl << "All Stats tests passed!" << std::endl;
  return 0;
}
