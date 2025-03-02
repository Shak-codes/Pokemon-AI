#ifndef _POKEMON_ENUMS_
#define _POKEMON_ENUMS_

#include <unordered_map>


enum class StatusEffect { NONE, PARALYSIS, POISON, BURN, SLEEP, FREEZE };
enum class Effect { NONE, STATUS, BUFF, DEBUFF, HEAL };
enum class Type {
  Normal,
  Fire,
  Water,
  Electric,
  Grass,
  Ice,
  Fighting,
  Poison,
  Ground,
  Flying,
  Psychic,
  Bug,
  Rock,
  Ghost,
  Dragon,
  Dark,
  Steel,
  Fairy
};

const std::unordered_map<std::string, Type> typeMap = {
    {"Normal", Type::Normal},
    {"Fire", Type::Fire},
    {"Water", Type::Water},
    {"Electric", Type::Electric},
    {"Grass", Type::Grass},
    {"Ice", Type::Ice},
    {"Fighting", Type::Fighting},
    {"Poison", Type::Poison},
    {"Ground", Type::Ground},
    {"Flying", Type::Flying},
    {"Psychic", Type::Psychic},
    {"Bug", Type::Bug},
    {"Rock", Type::Rock},
    {"Ghost", Type::Ghost},
    {"Dragon", Type::Dragon},
    {"Dark", Type::Dark},
    {"Steel", Type::Steel},
    {"Fairy", Type::Fairy}
};

Type stringToType(const std::string& typeStr) {
    auto it = typeMap.find(typeStr);
    return (it != typeMap.end()) ? it->second : Type::Normal;
}

enum class Category { Physical, Special, Status, None };

const std::unordered_map<std::string, Category> categoryMap = {
  {"Physical", Category::Physical},
  {"Special", Category::Special},
  {"Status", Category::Status}
};

Category stringToCategory(const std::string& categoryStr) {
    auto it = categoryMap.find(categoryStr);
    return (it != categoryMap.end()) ? it->second : Category::Physical;
}

enum class Status { None, Paralysis, Burn, Poison, Badly_Poison, Flinch, Recharge, Charge, }

#endif