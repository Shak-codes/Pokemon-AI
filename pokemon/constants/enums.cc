#include "enums.h"

#include <string>
#include <unordered_map>

const std::unordered_map<std::string, Type> typeMap = {
    {"Normal", Type::Normal},     {"Fire", Type::Fire},
    {"Water", Type::Water},       {"Electric", Type::Electric},
    {"Grass", Type::Grass},       {"Ice", Type::Ice},
    {"Fighting", Type::Fighting}, {"Poison", Type::Poison},
    {"Ground", Type::Ground},     {"Flying", Type::Flying},
    {"Psychic", Type::Psychic},   {"Bug", Type::Bug},
    {"Rock", Type::Rock},         {"Ghost", Type::Ghost},
    {"Dragon", Type::Dragon},     {"Dark", Type::Dark},
    {"Steel", Type::Steel},       {"Fairy", Type::Fairy}};

const std::unordered_map<std::string, Category> categoryMap = {
    {"Physical", Category::Physical},
    {"Special", Category::Special},
    {"Status", Category::Status}};

Type stringToType(const std::string& typeStr) {
  auto it = typeMap.find(typeStr);
  return (it != typeMap.end()) ? it->second : Type::Normal;
}

Category stringToCategory(const std::string& categoryStr) {
  auto it = categoryMap.find(categoryStr);
  return (it != categoryMap.end()) ? it->second : Category::Physical;
}