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

Category stringToCategory(const std::string& categoryStr) {
  auto it = categoryMap.find(categoryStr);
  return (it != categoryMap.end()) ? it->second : Category::Physical;
}

Type stringToType(const std::string& typeStr) {
  auto it = typeMap.find(typeStr);
  if (it != typeMap.end()) {
    return it->second;
  }
  return Type::Normal;
}

std::string typeToString(Type type) {
  for (const auto& pair : typeMap) {
    if (pair.second == type) {
      return pair.first;
    }
  }
  return "Normal";
}

std::string statusEffectToString(StatusEffect status) {
  switch (status) {
    case StatusEffect::None:
      return "None";
    case StatusEffect::Paralysis:
      return "Paralysis";
    case StatusEffect::Poison:
      return "Poison";
    case StatusEffect::Burn:
      return "Burn";
    case StatusEffect::Sleep:
      return "Sleep";
    case StatusEffect::Freeze:
      return "Freeze";
    case StatusEffect::Badly_Poisoned:
      return "Badly_Poisoned";
    default:
      return "None";
  }
}