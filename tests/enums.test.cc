#include "../pokemon/constants/enums.h"

#include <cassert>
#include <iostream>
#include <string>

void testStringToType() {
  assert(stringToType("Normal") == Type::Normal && "Normal type conversion");
  assert(stringToType("Fire") == Type::Fire && "Fire type conversion");
  assert(stringToType("Water") == Type::Water && "Water type conversion");
  assert(stringToType("Electric") == Type::Electric &&
         "Electric type conversion");
  assert(stringToType("Grass") == Type::Grass && "Grass type conversion");
  assert(stringToType("Ice") == Type::Ice && "Ice type conversion");
  assert(stringToType("Fighting") == Type::Fighting &&
         "Fighting type conversion");
  assert(stringToType("Poison") == Type::Poison && "Poison type conversion");
  assert(stringToType("Ground") == Type::Ground && "Ground type conversion");
  assert(stringToType("Flying") == Type::Flying && "Flying type conversion");
  assert(stringToType("Psychic") == Type::Psychic && "Psychic type conversion");
  assert(stringToType("Bug") == Type::Bug && "Bug type conversion");
  assert(stringToType("Rock") == Type::Rock && "Rock type conversion");
  assert(stringToType("Ghost") == Type::Ghost && "Ghost type conversion");
  assert(stringToType("Dragon") == Type::Dragon && "Dragon type conversion");
  assert(stringToType("Dark") == Type::Dark && "Dark type conversion");
  assert(stringToType("Steel") == Type::Steel && "Steel type conversion");
  assert(stringToType("Fairy") == Type::Fairy && "Fairy type conversion");

  // Test invalid type defaults to Normal
  assert(stringToType("InvalidType") == Type::Normal &&
         "Invalid type should default to Normal");
  assert(stringToType("") == Type::Normal &&
         "Empty string should default to Normal");

  std::cout << "  stringToType tests passed!" << std::endl;
}

void testTypeToString() {
  assert(typeToString(Type::Normal) == "Normal" && "Normal to string");
  assert(typeToString(Type::Fire) == "Fire" && "Fire to string");
  assert(typeToString(Type::Water) == "Water" && "Water to string");
  assert(typeToString(Type::Electric) == "Electric" && "Electric to string");
  assert(typeToString(Type::Grass) == "Grass" && "Grass to string");
  assert(typeToString(Type::Ice) == "Ice" && "Ice to string");
  assert(typeToString(Type::Fighting) == "Fighting" && "Fighting to string");
  assert(typeToString(Type::Poison) == "Poison" && "Poison to string");
  assert(typeToString(Type::Ground) == "Ground" && "Ground to string");
  assert(typeToString(Type::Flying) == "Flying" && "Flying to string");
  assert(typeToString(Type::Psychic) == "Psychic" && "Psychic to string");
  assert(typeToString(Type::Bug) == "Bug" && "Bug to string");
  assert(typeToString(Type::Rock) == "Rock" && "Rock to string");
  assert(typeToString(Type::Ghost) == "Ghost" && "Ghost to string");
  assert(typeToString(Type::Dragon) == "Dragon" && "Dragon to string");
  assert(typeToString(Type::Dark) == "Dark" && "Dark to string");
  assert(typeToString(Type::Steel) == "Steel" && "Steel to string");
  assert(typeToString(Type::Fairy) == "Fairy" && "Fairy to string");

  std::cout << "  typeToString tests passed!" << std::endl;
}

void testStringToCategory() {
  assert(stringToCategory("Physical") == Category::Physical &&
         "Physical category conversion");
  assert(stringToCategory("Special") == Category::Special &&
         "Special category conversion");
  assert(stringToCategory("Status") == Category::Status &&
         "Status category conversion");
  assert(stringToCategory("Invalid") == Category::Physical &&
         "Invalid category should default to Physical");

  std::cout << "  stringToCategory tests passed!" << std::endl;
}

void testStatusEffectToString() {
  assert(statusEffectToString(StatusEffect::None) == "None" &&
         "None status to string");
  assert(statusEffectToString(StatusEffect::Paralysis) == "Paralysis" &&
         "Paralysis status to string");
  assert(statusEffectToString(StatusEffect::Poison) == "Poison" &&
         "Poison status to string");
  assert(statusEffectToString(StatusEffect::Burn) == "Burn" &&
         "Burn status to string");
  assert(statusEffectToString(StatusEffect::Sleep) == "Sleep" &&
         "Sleep status to string");
  assert(statusEffectToString(StatusEffect::Freeze) == "Freeze" &&
         "Freeze status to string");
  assert(statusEffectToString(StatusEffect::Badly_Poisoned) == "Badly_Poisoned" &&
         "Badly_Poisoned status to string");

  std::cout << "  statusEffectToString tests passed!" << std::endl;
}

void testRoundTrip() {
  // Test that type -> string -> type works correctly
  Type types[] = {Type::Normal,   Type::Fire,   Type::Water,  Type::Electric,
                  Type::Grass,    Type::Ice,    Type::Fighting, Type::Poison,
                  Type::Ground,   Type::Flying, Type::Psychic,  Type::Bug,
                  Type::Rock,     Type::Ghost,  Type::Dragon,   Type::Dark,
                  Type::Steel,    Type::Fairy};

  for (Type t : types) {
    std::string str = typeToString(t);
    Type converted = stringToType(str);
    assert(converted == t && "Round-trip conversion failed");
  }

  std::cout << "  Round-trip conversion tests passed!" << std::endl;
}

int main() {
  std::cout << "Running Enums tests..." << std::endl;

  testStringToType();
  testTypeToString();
  testStringToCategory();
  testStatusEffectToString();
  testRoundTrip();

  std::cout << "All Enums tests passed!" << std::endl;
  return 0;
}
