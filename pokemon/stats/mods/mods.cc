#include "mods.h"

#include <cmath>

// Gen 1 stat stage multiplier calculation
// For positive stages: (2 + stage) / 2
// For negative stages: 2 / (2 - stage)
// This produces the exact Gen 1 multipliers:
// Stage -6: 2/8 = 0.25, Stage -5: 2/7 ≈ 0.28, Stage -4: 2/6 ≈ 0.33
// Stage -3: 2/5 = 0.4, Stage -2: 2/4 = 0.5, Stage -1: 2/3 ≈ 0.66
// Stage 0: 2/2 = 1.0
// Stage +1: 3/2 = 1.5, Stage +2: 4/2 = 2.0, Stage +3: 5/2 = 2.5
// Stage +4: 6/2 = 3.0, Stage +5: 7/2 = 3.5, Stage +6: 8/2 = 4.0
double Mods::calculateMultiplier(int stage) {
  if (stage >= 0) {
    return static_cast<double>(2 + stage) / 2.0;
  } else {
    return 2.0 / static_cast<double>(2 - stage);
  }
}

void Mods::reset() {
  attack = 0;
  defense = 0;
  special = 0;
  speed = 0;
  accuracy = 0;
  evasion = 0;
}

void Mods::modifyAttack(int value) {
  attack = std::clamp(attack + value, -6, 6);
}

void Mods::modifyDefense(int value) {
  defense = std::clamp(defense + value, -6, 6);
}

void Mods::modifySpecial(int value) {
  special = std::clamp(special + value, -6, 6);
}

void Mods::modifySpeed(int value) {
  speed = std::clamp(speed + value, -6, 6);
}

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

double Mods::getAttackMultiplier() const {
  return calculateMultiplier(attack);
}

double Mods::getDefenseMultiplier() const {
  return calculateMultiplier(defense);
}

double Mods::getSpecialMultiplier() const {
  return calculateMultiplier(special);
}

double Mods::getSpeedMultiplier() const {
  return calculateMultiplier(speed);
}

double Mods::getAccuracyMultiplier() const {
  return calculateMultiplier(accuracy);
}

double Mods::getEvasionMultiplier() const {
  return calculateMultiplier(evasion);
}

double Mods::getMultiplier(const std::string& stat) const {
  if (stat == "attack") return getAttackMultiplier();
  if (stat == "defense") return getDefenseMultiplier();
  if (stat == "special") return getSpecialMultiplier();
  if (stat == "speed") return getSpeedMultiplier();
  if (stat == "accuracy") return getAccuracyMultiplier();
  if (stat == "evasion") return getEvasionMultiplier();
  return 1.0;
}

// Apply stat stage multiplier to a base stat value
// Result is floored and clamped between 1 and 999
int Mods::applyToStat(int baseStat, const std::string& stat) const {
  double multiplier = getMultiplier(stat);
  int modifiedStat = static_cast<int>(std::floor(baseStat * multiplier));
  return std::clamp(modifiedStat, 1, 999);
}

bool Mods::canIncreaseAttack() const { return attack < 6; }
bool Mods::canIncreaseDefense() const { return defense < 6; }
bool Mods::canIncreaseSpecial() const { return special < 6; }
bool Mods::canIncreaseSpeed() const { return speed < 6; }
bool Mods::canIncreaseAccuracy() const { return accuracy < 6; }
bool Mods::canIncreaseEvasion() const { return evasion < 6; }

bool Mods::canDecreaseAttack() const { return attack > -6; }
bool Mods::canDecreaseDefense() const { return defense > -6; }
bool Mods::canDecreaseSpecial() const { return special > -6; }
bool Mods::canDecreaseSpeed() const { return speed > -6; }
bool Mods::canDecreaseAccuracy() const { return accuracy > -6; }
bool Mods::canDecreaseEvasion() const { return evasion > -6; }

bool Mods::canIncrease(const std::string& stat) const {
  if (stat == "attack") return canIncreaseAttack();
  if (stat == "defense") return canIncreaseDefense();
  if (stat == "special") return canIncreaseSpecial();
  if (stat == "speed") return canIncreaseSpeed();
  if (stat == "accuracy") return canIncreaseAccuracy();
  if (stat == "evasion") return canIncreaseEvasion();
  return false;
}

bool Mods::canDecrease(const std::string& stat) const {
  if (stat == "attack") return canDecreaseAttack();
  if (stat == "defense") return canDecreaseDefense();
  if (stat == "special") return canDecreaseSpecial();
  if (stat == "speed") return canDecreaseSpeed();
  if (stat == "accuracy") return canDecreaseAccuracy();
  if (stat == "evasion") return canDecreaseEvasion();
  return false;
}