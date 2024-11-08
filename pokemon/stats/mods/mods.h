#include <algorithm>
#include <iostream>

class Mods {
 private:
  int attack = 0;
  int defense = 0;
  int special = 0;
  int speed = 0;
  int accuracy = 0;
  int evasion = 0;

 public:
  void reset();

  void modifyAttack(int mod);
  void modifyDefense(int mod);
  void modifySpecial(int mod);
  void modifySpeed(int mod);
  void modifyAccuracy(int mod);
  void modifyEvasion(int mod);

  int getAttack() const;
  int getDefense() const;
  int getSpecial() const;
  int getSpeed() const;
  int getAccuracy() const;
  int getEvasion() const;
};
