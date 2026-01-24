#include "../pokemon/constants/type-matchups.h"

#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

// Helper to check floating point equality
bool approxEqual(double a, double b, double epsilon = 0.001) {
  return std::fabs(a - b) < epsilon;
}

// =============================================================================
// GEN 1 TYPE CHART TESTS
// =============================================================================

void testGen1SuperEffective() {
  std::cout << "  Testing Gen 1 super effective (2x) matchups..." << std::endl;

  // Fire is super effective against Grass, Ice, Bug
  assert(approxEqual(getTypeEffectiveness(gen1TypeMatchups, Type::Fire, Type::Grass), 2.0) &&
         "Fire vs Grass");
  assert(approxEqual(getTypeEffectiveness(gen1TypeMatchups, Type::Fire, Type::Ice), 2.0) &&
         "Fire vs Ice");
  assert(approxEqual(getTypeEffectiveness(gen1TypeMatchups, Type::Fire, Type::Bug), 2.0) &&
         "Fire vs Bug");

  // Water is super effective against Fire, Ground, Rock
  assert(approxEqual(getTypeEffectiveness(gen1TypeMatchups, Type::Water, Type::Fire), 2.0) &&
         "Water vs Fire");
  assert(approxEqual(getTypeEffectiveness(gen1TypeMatchups, Type::Water, Type::Ground), 2.0) &&
         "Water vs Ground");
  assert(approxEqual(getTypeEffectiveness(gen1TypeMatchups, Type::Water, Type::Rock), 2.0) &&
         "Water vs Rock");

  // Psychic is super effective against Fighting, Poison
  assert(approxEqual(getTypeEffectiveness(gen1TypeMatchups, Type::Psychic, Type::Fighting), 2.0) &&
         "Psychic vs Fighting");
  assert(approxEqual(getTypeEffectiveness(gen1TypeMatchups, Type::Psychic, Type::Poison), 2.0) &&
         "Psychic vs Poison");

  // Poison was super effective against Bug
  assert(approxEqual(getTypeEffectiveness(gen1TypeMatchups, Type::Poison, Type::Bug), 2.0) &&
         "Poison vs Bug should be 2.0 in Gen 1");

  // Bug was super effective against Poison (2x)
  assert(approxEqual(getTypeEffectiveness(gen1TypeMatchups, Type::Bug, Type::Poison), 2.0) &&
         "Bug vs Poison should be 2.0 in Gen 1");

  // Poison is super effective against Grass
  assert(approxEqual(getTypeEffectiveness(gen1TypeMatchups, Type::Poison, Type::Grass), 2.0) &&
         "Poison vs Grass should be 2.0 in Gen 1");

  // Bug is super effective against Grass and Psychic
  assert(approxEqual(getTypeEffectiveness(gen1TypeMatchups, Type::Bug, Type::Grass), 2.0) &&
         "Bug vs Grass should be 2.0 in Gen 1");
  assert(approxEqual(getTypeEffectiveness(gen1TypeMatchups, Type::Bug, Type::Psychic), 2.0) &&
         "Bug vs Psychic should be 2.0 in Gen 1");

  std::cout << "    Gen 1 super effective tests passed!" << std::endl;
}

void testGen1Immunities() {
  std::cout << "  Testing Gen 1 immunities (0x) matchups..." << std::endl;

  // Normal has no effect on Ghost
  assert(approxEqual(getTypeEffectiveness(gen1TypeMatchups, Type::Normal, Type::Ghost), 0.0) &&
         "Normal vs Ghost");

  // Ghost has no effect on Normal
  assert(approxEqual(getTypeEffectiveness(gen1TypeMatchups, Type::Ghost, Type::Normal), 0.0) &&
         "Ghost vs Normal");

  // Fighting has no effect on Ghost
  assert(approxEqual(getTypeEffectiveness(gen1TypeMatchups, Type::Fighting, Type::Ghost), 0.0) &&
         "Fighting vs Ghost");

  // Ground has no effect on Flying
  assert(approxEqual(getTypeEffectiveness(gen1TypeMatchups, Type::Ground, Type::Flying), 0.0) &&
         "Ground vs Flying");

  // Electric has no effect on Ground
  assert(approxEqual(getTypeEffectiveness(gen1TypeMatchups, Type::Electric, Type::Ground), 0.0) &&
         "Electric vs Ground");

  assert(approxEqual(getTypeEffectiveness(gen1TypeMatchups, Type::Ghost, Type::Psychic), 0.0) &&
         "Ghost vs Psychic");

  std::cout << "    Gen 1 immunity tests passed!" << std::endl;
}

void testGen1IceFireNeutral() {
  std::cout << "  Testing Gen 1 Ice vs Fire (neutral)..." << std::endl;

  // Gen 1 specific: Ice deals neutral damage to Fire
  assert(approxEqual(getTypeEffectiveness(gen1TypeMatchups, Type::Ice, Type::Fire), 1.0) &&
         "Ice vs Fire should be 1.0 in Gen 1");

  std::cout << "    Gen 1 Ice/Fire neutral test passed!" << std::endl;
}

void testGen1DualTypeCalculation() {
  std::cout << "  Testing Gen 1 dual-type effectiveness..." << std::endl;

  // Water/Flying vs Electric
  std::vector<Type> waterFlying = {Type::Water, Type::Flying};
  assert(approxEqual(getTypeEffectiveness(gen1TypeMatchups, Type::Electric, waterFlying), 4.0) &&
         "Electric vs Water/Flying should be 4x");

  // Water/Flying vs Ground
  assert(approxEqual(getTypeEffectiveness(gen1TypeMatchups, Type::Ground, waterFlying), 0.0) &&
         "Ground vs Water/Flying should be 0x (Flying immunity)");

  // Bug/Poison vs Psychic in Gen 1:
  std::vector<Type> bugPoison = {Type::Bug, Type::Poison};
  assert(approxEqual(getTypeEffectiveness(gen1TypeMatchups, Type::Psychic, bugPoison), 2.0) &&
         "Psychic vs Bug/Poison should be 2x in Gen 1");

  std::cout << "    Gen 1 dual-type calculation tests passed!" << std::endl;
}

// =============================================================================
// MODERN TYPE CHART TESTS (Gen 6+)
// =============================================================================

void testModernSuperEffective() {
  std::cout << "  Testing Modern super effective (2x) matchups..." << std::endl;

  // Ghost is super effective against Psychic (fixed from Gen 1)
  assert(approxEqual(getTypeEffectiveness(modernTypeMatchups, Type::Ghost, Type::Psychic), 2.0) &&
         "Ghost vs Psychic should be 2.0 in modern");

  // Dark is super effective against Psychic and Ghost
  assert(approxEqual(getTypeEffectiveness(modernTypeMatchups, Type::Dark, Type::Psychic), 2.0) &&
         "Dark vs Psychic");
  assert(approxEqual(getTypeEffectiveness(modernTypeMatchups, Type::Dark, Type::Ghost), 2.0) &&
         "Dark vs Ghost");

  // Steel is super effective against Ice, Rock, Fairy
  assert(approxEqual(getTypeEffectiveness(modernTypeMatchups, Type::Steel, Type::Ice), 2.0) &&
         "Steel vs Ice");
  assert(approxEqual(getTypeEffectiveness(modernTypeMatchups, Type::Steel, Type::Rock), 2.0) &&
         "Steel vs Rock");
  assert(approxEqual(getTypeEffectiveness(modernTypeMatchups, Type::Steel, Type::Fairy), 2.0) &&
         "Steel vs Fairy");

  // Fairy is super effective against Fighting, Dragon, Dark
  assert(approxEqual(getTypeEffectiveness(modernTypeMatchups, Type::Fairy, Type::Fighting), 2.0) &&
         "Fairy vs Fighting");
  assert(approxEqual(getTypeEffectiveness(modernTypeMatchups, Type::Fairy, Type::Dragon), 2.0) &&
         "Fairy vs Dragon");
  assert(approxEqual(getTypeEffectiveness(modernTypeMatchups, Type::Fairy, Type::Dark), 2.0) &&
         "Fairy vs Dark");

  // Fighting is super effective against Dark and Steel
  assert(approxEqual(getTypeEffectiveness(modernTypeMatchups, Type::Fighting, Type::Dark), 2.0) &&
         "Fighting vs Dark");
  assert(approxEqual(getTypeEffectiveness(modernTypeMatchups, Type::Fighting, Type::Steel), 2.0) &&
         "Fighting vs Steel");

  std::cout << "    Modern super effective tests passed!" << std::endl;
}

void testModernImmunities() {
  std::cout << "  Testing Modern immunities (0x) matchups..." << std::endl;

  // Psychic has no effect on Dark
  assert(approxEqual(getTypeEffectiveness(modernTypeMatchups, Type::Psychic, Type::Dark), 0.0) &&
         "Psychic vs Dark");

  // Dragon has no effect on Fairy
  assert(approxEqual(getTypeEffectiveness(modernTypeMatchups, Type::Dragon, Type::Fairy), 0.0) &&
         "Dragon vs Fairy");

  // Poison has no effect on Steel
  assert(approxEqual(getTypeEffectiveness(modernTypeMatchups, Type::Poison, Type::Steel), 0.0) &&
         "Poison vs Steel");

  // Ground has no effect on Flying
  assert(approxEqual(getTypeEffectiveness(modernTypeMatchups, Type::Ground, Type::Flying), 0.0) &&
         "Ground vs Flying");

  // Normal has no effect on Ghost
  assert(approxEqual(getTypeEffectiveness(modernTypeMatchups, Type::Normal, Type::Ghost), 0.0) &&
         "Normal vs Ghost");

  // Ghost has no effect on Normal
  assert(approxEqual(getTypeEffectiveness(modernTypeMatchups, Type::Ghost, Type::Normal), 0.0) &&
         "Ghost vs Normal");

  // Fighting has no effect on Ghost
  assert(approxEqual(getTypeEffectiveness(modernTypeMatchups, Type::Fighting, Type::Ghost), 0.0) &&
         "Fighting vs Ghost");

  std::cout << "    Modern immunity tests passed!" << std::endl;
}

void testModernPoisonBugInteraction() {
  std::cout << "  Testing Modern Poison/Bug interactions..." << std::endl;

  // In modern games, Poison is neutral against Bug
  assert(approxEqual(getTypeEffectiveness(modernTypeMatchups, Type::Poison, Type::Bug), 1.0) &&
         "Poison vs Bug should be 1.0 in modern");

  // In modern games, Bug is resisted by Poison
  assert(approxEqual(getTypeEffectiveness(modernTypeMatchups, Type::Bug, Type::Poison), 0.5) &&
         "Bug vs Poison should be 0.5 in modern");

  std::cout << "    Modern Poison/Bug interaction tests passed!" << std::endl;
}

void testModernIceFireResisted() {
  std::cout << "  Testing Modern Ice vs Fire (resisted)..." << std::endl;

  // Modern: Ice is resisted by Fire (0.5x)
  assert(approxEqual(getTypeEffectiveness(modernTypeMatchups, Type::Ice, Type::Fire), 0.5) &&
         "Ice vs Fire should be 0.5 in modern");

  std::cout << "    Modern Ice/Fire resisted test passed!" << std::endl;
}

void testModernDualTypeCalculation() {
  std::cout << "  Testing Modern dual-type effectiveness..." << std::endl;

  // Bug/Poison vs Psychic
  std::vector<Type> bugPoison = {Type::Bug, Type::Poison};
  assert(approxEqual(getTypeEffectiveness(modernTypeMatchups, Type::Psychic, bugPoison), 2.0) &&
         "Psychic vs Bug/Poison should be 2x in modern");

  // Fairy attacking Dragon/Flying:
  std::vector<Type> dragonFlying = {Type::Dragon, Type::Flying};
  assert(approxEqual(getTypeEffectiveness(modernTypeMatchups, Type::Fairy, dragonFlying), 2.0) &&
         "Fairy vs Dragon/Flying should be 2x");

  // Dragon attacking Fairy
  std::vector<Type> fairyOnly = {Type::Fairy};
  assert(approxEqual(getTypeEffectiveness(modernTypeMatchups, Type::Dragon, fairyOnly), 0.0) &&
         "Dragon vs Fairy should be 0x");

  // Steel/Fairy vs Poison
  std::vector<Type> steelFairy = {Type::Steel, Type::Fairy};
  assert(approxEqual(getTypeEffectiveness(modernTypeMatchups, Type::Poison, steelFairy), 0.0) &&
         "Poison vs Steel/Fairy should be 0x (Steel immunity)");

  std::cout << "    Modern dual-type calculation tests passed!" << std::endl;
}

// =============================================================================
// MAIN
// =============================================================================

int main() {
  std::cout << "Running Type Matchups tests..." << std::endl;
  std::cout << std::endl;

  std::cout << "=== Gen 1 Type Chart Tests ===" << std::endl;
  testGen1SuperEffective();
  testGen1Immunities();
  testGen1IceFireNeutral();
  testGen1DualTypeCalculation();

  std::cout << std::endl;
  std::cout << "=== Modern Type Chart Tests (Gen 6+) ===" << std::endl;
  testModernSuperEffective();
  testModernImmunities();
  testModernPoisonBugInteraction();
  testModernIceFireResisted();
  testModernDualTypeCalculation();

  std::cout << std::endl;
  std::cout << "All Type Matchups tests passed!" << std::endl;
  return 0;
}
