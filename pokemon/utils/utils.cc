#include "utils.h"

#include <iostream>
#include <random>
#include <stdexcept>
#include <string>
#include <unordered_map>

Target stringToTarget(const std::string& target) {
  static const std::unordered_map<std::string, Target> stringToTargetMap = {
      {"Opponent", Target::Opponent}, {"Self", Target::Self}};

  auto it = stringToTargetMap.find(target);
  if (it != stringToTargetMap.end()) {
    return it->second;
  } else {
    throw std::invalid_argument("Invalid target string: " + target);
  }
}

Category stringToCategory(const std::string& category) {
  static const std::unordered_map<std::string, Category> stringToCategoryMap = {
      {"Physical", Category::Physical},
      {"Special", Category::Special},
      {"Status", Category::Status},
      {"None", Category::None}};

  auto it = stringToCategoryMap.find(category);
  if (it != stringToCategoryMap.end()) {
    return it->second;
  } else {
    throw std::invalid_argument("Invalid category string: " + category);
  }
}

Type stringToType(const std::string& type) {
  static const std::unordered_map<std::string, Type> stringToTypeMap = {
      {"Normal", Type::Normal},     {"Fire", Type::Fire},
      {"Water", Type::Water},       {"Electric", Type::Electric},
      {"Grass", Type::Grass},       {"Ice", Type::Ice},
      {"Fighting", Type::Fighting}, {"Poison", Type::Poison},
      {"Ground", Type::Ground},     {"Flying", Type::Flying},
      {"Psychic", Type::Psychic},   {"Bug", Type::Bug},
      {"Rock", Type::Rock},         {"Ghost", Type::Ghost},
      {"Dragon", Type::Dragon},     {"Dark", Type::Dark},
      {"Steel", Type::Steel},       {"Fairy", Type::Fairy}};

  auto it = stringToTypeMap.find(type);
  if (it != stringToTypeMap.end()) {
    return it->second;
  } else {
    throw std::invalid_argument("Invalid type string: " + type);
  }
}

bool doesMoveHit(const Move& move) {
  float effectiveAccuracy = move.getAcc();

  static std::random_device rd;
  static std::mt19937 gen(rd());
  std::uniform_real_distribution<float> dis(0.0, 1.0);

  return dis(gen) < effectiveAccuracy;
}

Move createMoveFromJson(const json& moveData) {
  std::string name = moveData["name"];
  Type type = stringToType(moveData["type"]);
  Category category = stringToCategory(moveData["category"]);
  Target target = stringToTarget(moveData["target"]);
  int power = moveData["power"];
  float accuracy = moveData["accuracy"];
  int pp = moveData["pp"];
  bool special = false;
  if (moveData["accuracy"] == false) {
    special = true;
  }
  if (moveData["pp"] == false) {
    special = true;
  }

  return Move(name, type, category, target, power, accuracy, pp, special);
}
