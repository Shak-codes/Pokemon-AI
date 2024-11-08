#include "mods.h"

void Mods::reset() {
  attack = 0;
  defense = 0;
  special = 0;
  speed = 0;
  accuracy = 0;
  evasion = 0;
}

void Mods::modifyAttack(int mod) { attack = std::clamp(attack + mod, -6, 6); }

void Mods::modifyDefense(int mod) {
  defense = std::clamp(defense + mod, -6, 6);
}

void Mods::modifySpecial(int mod) {
  special = std::clamp(special + mod, -6, 6);
}

void Mods::modifySpeed(int mod) { speed = std::clamp(speed + mod, -6, 6); }

void Mods::modifyAccuracy(int mod) {
  accuracy = std::clamp(accuracy + mod, -6, 6);
}

void Mods::modifyEvasion(int mod) {
  evasion = std::clamp(evasion + mod, -6, 6);
}

int Mods::getAttack() const { return attack; }
int Mods::getDefense() const { return defense; }
int Mods::getSpecial() const { return special; }
int Mods::getSpeed() const { return speed; }
int Mods::getAccuracy() const { return accuracy; }
int Mods::getEvasion() const { return evasion; }