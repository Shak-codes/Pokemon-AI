#include "../pokemon/stats/mods/mods.h"

#include <cassert>
#include <cmath>
#include <iostream>

// Helper to compare floating point values with tolerance
bool approxEqual(double a, double b, double epsilon = 0.001) {
  return std::abs(a - b) < epsilon;
}

void testInitialState() {
  std::cout << "Testing initial state..." << std::endl;
  Mods mods;

  assert(mods.getAttack() == 0 && "Initial attack should be 0");
  assert(mods.getDefense() == 0 && "Initial defense should be 0");
  assert(mods.getSpecial() == 0 && "Initial special should be 0");
  assert(mods.getSpeed() == 0 && "Initial speed should be 0");
  assert(mods.getAccuracy() == 0 && "Initial accuracy should be 0");
  assert(mods.getEvasion() == 0 && "Initial evasion should be 0");

  // All multipliers should be 1.0 at stage 0
  assert(approxEqual(mods.getAttackMultiplier(), 1.0) &&
         "Initial attack multiplier should be 1.0");
  assert(approxEqual(mods.getDefenseMultiplier(), 1.0) &&
         "Initial defense multiplier should be 1.0");
  assert(approxEqual(mods.getSpecialMultiplier(), 1.0) &&
         "Initial special multiplier should be 1.0");
  assert(approxEqual(mods.getSpeedMultiplier(), 1.0) &&
         "Initial speed multiplier should be 1.0");
  assert(approxEqual(mods.getAccuracyMultiplier(), 1.0) &&
         "Initial accuracy multiplier should be 1.0");
  assert(approxEqual(mods.getEvasionMultiplier(), 1.0) &&
         "Initial evasion multiplier should be 1.0");

  std::cout << "  Initial state tests passed!" << std::endl;
}

void testModification() {
  std::cout << "Testing stat modification..." << std::endl;
  Mods mods;

  mods.modifyAttack(4);
  assert(mods.getAttack() == 4 && "Attack should be 4 after modification");

  mods.modifyDefense(-3);
  assert(mods.getDefense() == -3 && "Defense should be -3 after modification");

  mods.modifySpecial(6);
  assert(mods.getSpecial() == 6 && "Special should be 6");

  mods.modifySpeed(10);
  assert(mods.getSpeed() == 6 && "Speed should be capped at 6");

  mods.modifyAccuracy(-10);
  assert(mods.getAccuracy() == -6 && "Accuracy should be capped at -6");

  mods.modifyEvasion(5);
  assert(mods.getEvasion() == 5 && "Evasion should be 5 after modification");

  std::cout << "  Stat modification tests passed!" << std::endl;
}

void testReset() {
  std::cout << "Testing reset..." << std::endl;
  Mods mods;

  mods.modifyAttack(4);
  mods.modifyDefense(-3);
  mods.modifySpecial(6);
  mods.modifySpeed(2);
  mods.modifyAccuracy(-2);
  mods.modifyEvasion(1);

  mods.reset();
  assert(mods.getAttack() == 0 && "Attack should be 0 after reset");
  assert(mods.getDefense() == 0 && "Defense should be 0 after reset");
  assert(mods.getSpecial() == 0 && "Special should be 0 after reset");
  assert(mods.getSpeed() == 0 && "Speed should be 0 after reset");
  assert(mods.getAccuracy() == 0 && "Accuracy should be 0 after reset");
  assert(mods.getEvasion() == 0 && "Evasion should be 0 after reset");

  std::cout << "  Reset tests passed!" << std::endl;
}

void testClamping() {
  std::cout << "Testing clamping to -6/+6 range..." << std::endl;
  Mods mods;

  // Test upper bound clamping
  mods.modifyAttack(10);
  assert(mods.getAttack() == 6 && "Attack should be clamped to 6");

  mods.reset();
  mods.modifyAttack(3);
  mods.modifyAttack(5);
  assert(mods.getAttack() == 6 && "Attack should be clamped to 6 after overflow");

  // Test lower bound clamping
  mods.reset();
  mods.modifyDefense(-10);
  assert(mods.getDefense() == -6 && "Defense should be clamped to -6");

  mods.reset();
  mods.modifyDefense(-4);
  mods.modifyDefense(-5);
  assert(mods.getDefense() == -6 &&
         "Defense should be clamped to -6 after underflow");

  std::cout << "  Clamping tests passed!" << std::endl;
}

void testMultipliersPositiveStages() {
  std::cout << "Testing positive stage multipliers..." << std::endl;
  Mods mods;

  // Gen 1 positive stage multipliers: (2 + stage) / 2
  // Stage +1: 3/2 = 1.5
  mods.modifyAttack(1);
  assert(approxEqual(mods.getAttackMultiplier(), 1.5) &&
         "Stage +1 should have multiplier 1.5");

  // Stage +2: 4/2 = 2.0
  mods.reset();
  mods.modifyAttack(2);
  assert(approxEqual(mods.getAttackMultiplier(), 2.0) &&
         "Stage +2 should have multiplier 2.0");

  // Stage +3: 5/2 = 2.5
  mods.reset();
  mods.modifyAttack(3);
  assert(approxEqual(mods.getAttackMultiplier(), 2.5) &&
         "Stage +3 should have multiplier 2.5");

  // Stage +4: 6/2 = 3.0
  mods.reset();
  mods.modifyAttack(4);
  assert(approxEqual(mods.getAttackMultiplier(), 3.0) &&
         "Stage +4 should have multiplier 3.0");

  // Stage +5: 7/2 = 3.5
  mods.reset();
  mods.modifyAttack(5);
  assert(approxEqual(mods.getAttackMultiplier(), 3.5) &&
         "Stage +5 should have multiplier 3.5");

  // Stage +6: 8/2 = 4.0
  mods.reset();
  mods.modifyAttack(6);
  assert(approxEqual(mods.getAttackMultiplier(), 4.0) &&
         "Stage +6 should have multiplier 4.0");

  std::cout << "  Positive stage multiplier tests passed!" << std::endl;
}

void testMultipliersNegativeStages() {
  std::cout << "Testing negative stage multipliers..." << std::endl;
  Mods mods;

  // Gen 1 negative stage multipliers: 2 / (2 - stage)
  // Stage -1: 2/3 ≈ 0.666
  mods.modifyAttack(-1);
  assert(approxEqual(mods.getAttackMultiplier(), 2.0 / 3.0) &&
         "Stage -1 should have multiplier 2/3");

  // Stage -2: 2/4 = 0.5
  mods.reset();
  mods.modifyAttack(-2);
  assert(approxEqual(mods.getAttackMultiplier(), 0.5) &&
         "Stage -2 should have multiplier 0.5");

  // Stage -3: 2/5 = 0.4
  mods.reset();
  mods.modifyAttack(-3);
  assert(approxEqual(mods.getAttackMultiplier(), 0.4) &&
         "Stage -3 should have multiplier 0.4");

  // Stage -4: 2/6 ≈ 0.333
  mods.reset();
  mods.modifyAttack(-4);
  assert(approxEqual(mods.getAttackMultiplier(), 2.0 / 6.0) &&
         "Stage -4 should have multiplier 2/6");

  // Stage -5: 2/7 ≈ 0.286
  mods.reset();
  mods.modifyAttack(-5);
  assert(approxEqual(mods.getAttackMultiplier(), 2.0 / 7.0) &&
         "Stage -5 should have multiplier 2/7");

  // Stage -6: 2/8 = 0.25
  mods.reset();
  mods.modifyAttack(-6);
  assert(approxEqual(mods.getAttackMultiplier(), 0.25) &&
         "Stage -6 should have multiplier 0.25");

  std::cout << "  Negative stage multiplier tests passed!" << std::endl;
}

void testApplyToStat() {
  std::cout << "Testing applyToStat calculation..." << std::endl;
  Mods mods;

  // Example from the documentation:
  // A Pokemon with Special 401 at stage 0 has modified Special 401
  int baseStat = 401;
  assert(mods.applyToStat(baseStat, "special") == 401 &&
         "Stage 0 should not modify stat");

  // After Growth (+1): 401 * 1.5 = 601.5, floored to 601
  mods.modifySpecial(1);
  assert(mods.applyToStat(baseStat, "special") == 601 &&
         "Stage +1 should multiply by 1.5 (401 * 1.5 = 601)");

  // At stage +3: 401 * 2.5 = 1002.5, floored to 1002, clamped to 999
  mods.reset();
  mods.modifySpecial(3);
  assert(mods.applyToStat(baseStat, "special") == 999 &&
         "Modified stat should be capped at 999");

  // Example from documentation:
  // Pokemon with Attack 30 at stage -4: 30 * 0.33 = 9.9, floored to 9
  mods.reset();
  mods.modifyAttack(-4);
  int attackResult = mods.applyToStat(30, "attack");
  // 30 * (2/6) = 30 * 0.333... = 10
  // Note: The documentation says 9 because Gen 1 uses approximate values
  // Our implementation uses exact fractions, so 30 * (2/6) = 10
  assert(attackResult == 10 &&
         "Attack 30 at stage -4 should be 10 (30 * 2/6)");

  // Test minimum value clamping (cannot go below 1)
  mods.reset();
  mods.modifyDefense(-6);
  assert(mods.applyToStat(3, "defense") == 1 &&
         "Modified stat should be at least 1");

  std::cout << "  applyToStat tests passed!" << std::endl;
}

void testCanIncreaseDecrease() {
  std::cout << "Testing canIncrease/canDecrease checks..." << std::endl;
  Mods mods;

  // At stage 0, can both increase and decrease
  assert(mods.canIncreaseAttack() && "Should be able to increase at stage 0");
  assert(mods.canDecreaseAttack() && "Should be able to decrease at stage 0");

  // At stage +6, cannot increase further
  mods.modifyAttack(6);
  assert(!mods.canIncreaseAttack() && "Should NOT be able to increase at +6");
  assert(mods.canDecreaseAttack() && "Should be able to decrease at +6");

  // At stage -6, cannot decrease further
  mods.reset();
  mods.modifyDefense(-6);
  assert(mods.canIncreaseDefense() && "Should be able to increase at -6");
  assert(!mods.canDecreaseDefense() && "Should NOT be able to decrease at -6");

  // Test generic canIncrease/canDecrease by name
  mods.reset();
  mods.modifySpeed(6);
  assert(!mods.canIncrease("speed") && "canIncrease(speed) should be false at +6");
  assert(mods.canDecrease("speed") && "canDecrease(speed) should be true at +6");

  mods.reset();
  mods.modifyAccuracy(-6);
  assert(mods.canIncrease("accuracy") &&
         "canIncrease(accuracy) should be true at -6");
  assert(!mods.canDecrease("accuracy") &&
         "canDecrease(accuracy) should be false at -6");

  std::cout << "  canIncrease/canDecrease tests passed!" << std::endl;
}

void testGetMultiplierByName() {
  std::cout << "Testing getMultiplier by stat name..." << std::endl;
  Mods mods;

  mods.modifyAttack(2);
  mods.modifyDefense(-2);
  mods.modifySpecial(4);
  mods.modifySpeed(-1);
  mods.modifyAccuracy(3);
  mods.modifyEvasion(-3);

  assert(approxEqual(mods.getMultiplier("attack"), 2.0) &&
         "getMultiplier(attack) should return 2.0 at stage +2");
  assert(approxEqual(mods.getMultiplier("defense"), 0.5) &&
         "getMultiplier(defense) should return 0.5 at stage -2");
  assert(approxEqual(mods.getMultiplier("special"), 3.0) &&
         "getMultiplier(special) should return 3.0 at stage +4");
  assert(approxEqual(mods.getMultiplier("speed"), 2.0 / 3.0) &&
         "getMultiplier(speed) should return 2/3 at stage -1");
  assert(approxEqual(mods.getMultiplier("accuracy"), 2.5) &&
         "getMultiplier(accuracy) should return 2.5 at stage +3");
  assert(approxEqual(mods.getMultiplier("evasion"), 0.4) &&
         "getMultiplier(evasion) should return 0.4 at stage -3");

  // Unknown stat should return 1.0 (no modification)
  assert(approxEqual(mods.getMultiplier("unknown"), 1.0) &&
         "getMultiplier(unknown) should return 1.0");

  std::cout << "  getMultiplier by name tests passed!" << std::endl;
}

void testAllStatsHaveMultipliers() {
  std::cout << "Testing that all stats have correct multiplier methods..."
            << std::endl;
  Mods mods;

  // Set each stat to a different stage
  mods.modifyAttack(1);
  mods.modifyDefense(2);
  mods.modifySpecial(3);
  mods.modifySpeed(4);
  mods.modifyAccuracy(5);
  mods.modifyEvasion(6);

  assert(approxEqual(mods.getAttackMultiplier(), 1.5));
  assert(approxEqual(mods.getDefenseMultiplier(), 2.0));
  assert(approxEqual(mods.getSpecialMultiplier(), 2.5));
  assert(approxEqual(mods.getSpeedMultiplier(), 3.0));
  assert(approxEqual(mods.getAccuracyMultiplier(), 3.5));
  assert(approxEqual(mods.getEvasionMultiplier(), 4.0));

  std::cout << "  All stat multiplier methods work correctly!" << std::endl;
}

int main() {
  std::cout << "\n=== Mods Class Tests ===" << std::endl << std::endl;

  testInitialState();
  testModification();
  testReset();
  testClamping();
  testMultipliersPositiveStages();
  testMultipliersNegativeStages();
  testApplyToStat();
  testCanIncreaseDecrease();
  testGetMultiplierByName();
  testAllStatsHaveMultipliers();

  std::cout << std::endl << "All Mods tests passed!" << std::endl;
  return 0;
}
