#ifndef STATMODIFIERS
#define STATMODIFIERS

#include "../../../lib/json.hpp"
using json = nlohmann::json;

class StatModifiers {
 private:
  bool hasMods = false;
  int attackMod = 0;
  int defenseMod = 0;
  int specialMod = 0;
  int speedMod = 0;
  float attackChance = 0;
  float defenseChance = 0;
  float specialChance = 0;
  float speedChance = 0;

 public:
  StatModifiers(const json& mods);
  bool getHasMods() const;
  void setHasMods(bool value);

  int getAttackMod() const;
  void setAttackMod(int value);

  int getDefenseMod() const;
  void setDefenseMod(int value);

  int getSpecialMod() const;
  void setSpecialMod(int value);

  int getSpeedMod() const;
  void setSpeedMod(int value);

  float getAttackChance() const;
  void setAttackChance(float value);

  float getDefenseChance() const;
  void setDefenseChance(float value);

  float getSpecialChance() const;
  void setSpecialChance(float value);

  float getSpeedChance() const;
  void setSpeedChance(float value);
};

#endif
