#include "../pokemon/effects/status/status.h"

#include <cassert>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "../lib/json.hpp"

using json = nlohmann::json;

bool floatEquals(float a, float b, float epsilon = 0.0001f) {
  return std::fabs(a - b) < epsilon;
}

void testStatusClass() {
  std::cout << "\n=== Testing Status Class ===\n" << std::endl;

  // Test 1: Empty status (no effects)
  {
    std::cout << "Test 1: Empty status (no effects)... ";
    json emptyJson = json::object();
    Status emptyStatus(emptyJson);

    assert(!emptyStatus.hasEffect());
    assert(emptyStatus.getStatuses().empty());
    assert(floatEquals(emptyStatus.getChance("paralysis"), 0.0f));
    std::cout << "PASSED" << std::endl;
  }

  // Test 2: Single status effect with 100% chance
  {
    std::cout << "Test 2: Single status with 100% chance... ";
    json statusJson = {{"paralysis", 1.0f}};
    Status status(statusJson);

    assert(status.hasEffect());
    assert(status.getStatuses().size() == 1);
    assert(status.getStatuses()[0] == "paralysis");
    assert(floatEquals(status.getChance("paralysis"), 1.0f));
    assert(floatEquals(status.getChance("burn"), 0.0f));
    std::cout << "PASSED" << std::endl;
  }

  // Test 3: Single status effect with partial chance
  {
    std::cout << "Test 3: Single status with 30% chance... ";
    json statusJson = {{"burn", 0.3f}};
    Status status(statusJson);

    assert(status.hasEffect());
    assert(floatEquals(status.getChance("burn"), 0.3f));
    std::cout << "PASSED" << std::endl;
  }

  // Test 4: Various status effect types
  {
    std::cout << "Test 4: All status effect types... ";
    std::vector<std::pair<std::string, float>> testCases = {
        {"paralyze", 0.3f},       {"poison", 1.0f},
        {"badly-poisoned", 1.0f}, {"burn", 0.1f},
        {"sleep", 0.75f},         {"freeze", 0.1f},
        {"confusion", 0.5f}};

    for (size_t i = 0; i < testCases.size(); i++) {
      std::string statusType = testCases[i].first;
      float chance = testCases[i].second;
      json statusJson = {{statusType, chance}};
      Status status(statusJson);
      assert(status.hasEffect());
      assert(floatEquals(status.getChance(statusType), chance));
    }
    std::cout << "PASSED" << std::endl;
  }

  // Test 5: getStatusEffect returns correct map
  {
    std::cout << "Test 5: getStatusEffect returns correct map... ";
    json statusJson = {{"sleep", 0.6f}};
    Status status(statusJson);

    auto effectMap = status.getStatusEffect();
    assert(effectMap.size() == 1);
    assert(effectMap.count("sleep") == 1);
    assert(floatEquals(effectMap["sleep"], 0.6f));
    std::cout << "PASSED" << std::endl;
  }

  std::cout << "\nAll Status class tests PASSED!" << std::endl;
}

void testStatusFromMoves(const json& moves) {
  std::cout << "\n=== Testing Status Effects from moves.json ===\n"
            << std::endl;

  int movesWithStatus = 0;
  int movesWithoutStatus = 0;

  for (auto it = moves.begin(); it != moves.end(); ++it) {
    std::string moveName = it.key();
    const json& moveData = it.value();
    const auto& effects = moveData["effects"];

    // Check if move has status effects in JSON
    bool hasStatusInJson = effects.contains("status");
    json statusJson = effects.value("status", json::object());
    json userStatusJson = statusJson.value("user", json::object());
    json oppStatusJson = statusJson.value("opponent", json::object());

    // Create Status instances
    Status userStatus(userStatusJson);
    Status oppStatus(oppStatusJson);

    bool hasUserStatus = userStatus.hasEffect();
    bool hasOppStatus = oppStatus.hasEffect();

    if (hasStatusInJson && (hasUserStatus || hasOppStatus)) {
      // Move has status effect - verify the status data matches JSON
      std::cout << moveName << ": ";

      if (hasUserStatus) {
        // Verify user status effects match JSON
        for (auto statusIt = userStatusJson.begin();
             statusIt != userStatusJson.end(); ++statusIt) {
          std::string statusType = statusIt.key();
          float expectedChance = statusIt.value().get<float>();
          float actualChance = userStatus.getChance(statusType);
          assert(floatEquals(actualChance, expectedChance));
          std::cout << "user:" << statusType << "=" << actualChance << " ";
        }
        // Verify getStatuses() returns correct count
        assert(userStatus.getStatuses().size() == userStatusJson.size());
      }

      if (hasOppStatus) {
        // Verify opponent status effects match JSON
        for (auto statusIt = oppStatusJson.begin();
             statusIt != oppStatusJson.end(); ++statusIt) {
          std::string statusType = statusIt.key();
          float expectedChance = statusIt.value().get<float>();
          float actualChance = oppStatus.getChance(statusType);
          assert(floatEquals(actualChance, expectedChance));
          std::cout << "opp:" << statusType << "=" << actualChance << " ";
        }
        // Verify getStatuses() returns correct count
        assert(oppStatus.getStatuses().size() == oppStatusJson.size());
      }

      std::cout << "PASSED" << std::endl;
      movesWithStatus++;
    } else {
      // Move has no status effect - verify Status class reflects this
      assert(!hasUserStatus);
      assert(!hasOppStatus);
      assert(userStatus.getStatuses().empty());
      assert(oppStatus.getStatuses().empty());
      movesWithoutStatus++;
    }
  }

  std::cout << "\nSummary:" << std::endl;
  std::cout << "  Moves with status effects: " << movesWithStatus << std::endl;
  std::cout << "  Moves without status effects: " << movesWithoutStatus
            << std::endl;
  std::cout << "  Total moves tested: "
            << (movesWithStatus + movesWithoutStatus) << std::endl;

  std::cout << "\nAll moves.json Status tests PASSED!" << std::endl;
}

int main() {
  std::ifstream file("data/moves.json");
  if (!file.is_open()) {
    std::cerr << "Failed to open file" << std::endl;
    return 1;
  }

  json moves;
  file >> moves;

  file.close();

  if (moves.empty()) {
    std::cerr << "Error: 'moves' JSON object is empty!" << std::endl;
    return 1;
  }

  std::cout << "Imported moves!" << std::endl;

  testStatusClass();
  testStatusFromMoves(moves);

  std::cout << "\n==================================" << std::endl;
  std::cout << "All Status tests passed!" << std::endl;
  std::cout << "==================================" << std::endl;
  return 0;
}
