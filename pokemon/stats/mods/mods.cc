#include "mods.h"

void Mods::reset() {
  attack = 0;
  defense = 0;
  special = 0;
  speed = 0;
  accuracy = 0;
  evasion = 0;
}

void Mods::modifyAttack(int value) { attack = std::clamp(attack + value, -6, 6); }

void Mods::modifyDefense(int value) {
  defense = std::clamp(defense + value, -6, 6);
}

void Mods::modifySpecial(int value) {
  special = std::clamp(special + value, -6, 6);
}

void Mods::modifySpeed(int value) { speed = std::clamp(speed + value, -6, 6); }

void Mods::modifyAccuracy(int value) {
  accuracy = std::clamp(accuracy + value, -6, 6);
}

void Mods::modifyEvasion(int value) {
  evasion = std::clamp(evasion + value, -6, 6);
}

int Mods::getAttack() const { return attack; }
int Mods::getDefense() const { return defense; }
int Mods::getSpecial() const { return special; }
int Mods::getSpeed() const { return speed; }
int Mods::getAccuracy() const { return accuracy; }
int Mods::getEvasion() const { return evasion; }