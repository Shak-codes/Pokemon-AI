#ifndef _ENUMS_
#define _ENUMS_

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

enum class TrainerClass {
  Sailor,
  Pokemaniac,
  Burglar,
  Fisher,
  Swimmer,
  Beauty,
  Rocker,
  ProfOak,
  Giovanni,
  CooltrainerM,
  CooltrainerF,
  Misty,
  Surge,
  Erika,
  Koga,
  Blaine,
  Sabrina,
  Rival2,
  Rival3,
  Lorelei,
  Lance,
  SuperNerd,
  Juggler,
  Psychic,
  Chief,
  Scientist,
  Gentleman,
  Youngster,
  CueBall,
  Blackbelt,
  Bruno,
  Brock,
  Agatha
};

const std::string TrainerClassNames[] = {
    "Sailor",       "Pokemaniac", "Burglar",   "Fisher",   "Swimmer",
    "Beauty",       "Rocker",     "Prof. Oak", "Giovanni", "CooltrainerM",
    "CooltrainerF", "Misty",      "Surge",     "Erika",    "Koga",
    "Blaine",       "Sabrina",    "Rival2",    "Rival3",   "Lorelei",
    "Lance",        "SuperNerd",  "Juggler",   "Psychic",  "Chief",
    "Scientist",    "Gentleman",  "Youngster", "CueBall",  "Blackbelt",
    "Bruno",        "Brock",      "Agatha"};

#endif