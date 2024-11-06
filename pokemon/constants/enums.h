#ifndef _POKEMON_ENUMS_
#define _POKEMON_ENUMS_

enum class Status { NONE, PARALYSIS, POISON, BURN, SLEEP, FREEZE };
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
enum class Target { Opponent, Self };

#endif