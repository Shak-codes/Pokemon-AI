#ifndef __MODS__
#define __MODS__

#include <algorithm>
#include <string>

class Mods {
 private:
  int attack{0};
  int defense{0};
  int special{0};
  int speed{0};
  int accuracy{0};
  int evasion{0};

  // For positive stages: (2 + stage) / 2
  // For negative stages: 2 / (2 - stage)
  static double calculateMultiplier(int stage);

 public:
  void reset();

  void modifyAttack(int value);
  void modifyDefense(int value);
  void modifySpecial(int value);
  void modifySpeed(int value);
  void modifyAccuracy(int value);
  void modifyEvasion(int value);

  int getAttack() const;
  int getDefense() const;
  int getSpecial() const;
  int getSpeed() const;
  int getAccuracy() const;
  int getEvasion() const;

  double getAttackMultiplier() const;
  double getDefenseMultiplier() const;
  double getSpecialMultiplier() const;
  double getSpeedMultiplier() const;
  double getAccuracyMultiplier() const;
  double getEvasionMultiplier() const;

  double getMultiplier(const std::string& stat) const;

  // Apply stat stage multiplier to a base stat value
  // Result is floored and clamped between 1 and 999
  int applyToStat(int baseStat, const std::string& stat) const;

  bool canIncreaseAttack() const;
  bool canIncreaseDefense() const;
  bool canIncreaseSpecial() const;
  bool canIncreaseSpeed() const;
  bool canIncreaseAccuracy() const;
  bool canIncreaseEvasion() const;

  bool canDecreaseAttack() const;
  bool canDecreaseDefense() const;
  bool canDecreaseSpecial() const;
  bool canDecreaseSpeed() const;
  bool canDecreaseAccuracy() const;
  bool canDecreaseEvasion() const;

  bool canIncrease(const std::string& stat) const;
  bool canDecrease(const std::string& stat) const;
};

#endif
