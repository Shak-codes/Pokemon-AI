#ifndef _POKEMON_ENUMS_
#define _POKEMON_ENUMS_

#pragma once

#include <string>
#include <unordered_map>

enum class StatusEffect {
  None,
  Paralysis,
  Poison,
  Burn,
  Sleep,
  Freeze,
  Badly_Poisoned
};

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

enum class Category { Physical, Special, Status, None };

enum class Target { User, Opponent };

Category stringToCategory(const std::string& categoryStr);
Type stringToType(const std::string& typeStr);
std::string typeToString(Type type);
std::string statusEffectToString(StatusEffect status);

#endif