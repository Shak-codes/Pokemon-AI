#include "../pokemon/stats/mods/mods.h"

#include <cassert>
#include <iostream>

int main() {
  Mods mods;

  assert(mods.getAttack() == 0 && "Initial attack should be 0");
  assert(mods.getDefense() == 0 && "Initial defense should be 0");
  assert(mods.getSpecial() == 0 && "Initial special should be 0");
  assert(mods.getSpeed() == 0 && "Initial speed should be 0");
  assert(mods.getAccuracy() == 0 && "Initial accuracy should be 0");
  assert(mods.getEvasion() == 0 && "Initial evasion should be 0");

  mods.modifyAttack(4);
  assert(mods.getAttack() == 4 && "Attack should be 4 after modification");

  mods.modifyDefense(-3);
  assert(mods.getDefense() == -3 && "Defense should be -3 after modification");

  mods.modifySpecial(6);
  assert(mods.getSpecial() == 6 && "Special should be capped at 6");

  mods.modifySpeed(10);
  assert(mods.getSpeed() == 6 && "Speed should be capped at 6");

  mods.modifyAccuracy(-10);
  assert(mods.getAccuracy() == -6 && "Accuracy should be capped at -6");

  mods.modifyEvasion(5);
  assert(mods.getEvasion() == 5 && "Evasion should be 5 after modification");

  mods.reset();
  assert(mods.getAttack() == 0 && "Attack should be 0 after reset");
  assert(mods.getDefense() == 0 && "Defense should be 0 after reset");
  assert(mods.getSpecial() == 0 && "Special should be 0 after reset");
  assert(mods.getSpeed() == 0 && "Speed should be 0 after reset");
  assert(mods.getAccuracy() == 0 && "Accuracy should be 0 after reset");
  assert(mods.getEvasion() == 0 && "Evasion should be 0 after reset");

  std::cout << "All Mods tests passed!" << std::endl;
  return 0;
}
