#include "statModifiers.h"

#include "../../../lib/json.hpp"

using json = nlohmann::json;

StatModifiers::StatModifiers(const json& mods) {}

bool StatModifiers::getHasMods() const { return hasMods; }
void StatModifiers::setHasMods(bool value) { hasMods = value; }

int StatModifiers::getAttackMod() const { return attackMod; }
void StatModifiers::setAttackMod(int value) { attackMod = value; }

int StatModifiers::getDefenseMod() const { return defenseMod; }
void StatModifiers::setDefenseMod(int value) { defenseMod = value; }

int StatModifiers::getSpecialMod() const { return specialMod; }
void StatModifiers::setSpecialMod(int value) { specialMod = value; }

int StatModifiers::getSpeedMod() const { return speedMod; }
void StatModifiers::setSpeedMod(int value) { speedMod = value; }

float StatModifiers::getAttackChance() const { return attackChance; }
void StatModifiers::setAttackChance(float value) { attackChance = value; }

float StatModifiers::getDefenseChance() const { return defenseChance; }
void StatModifiers::setDefenseChance(float value) { defenseChance = value; }

float StatModifiers::getSpecialChance() const { return specialChance; }
void StatModifiers::setSpecialChance(float value) { specialChance = value; }

float StatModifiers::getSpeedChance() const { return speedChance; }
void StatModifiers::setSpeedChance(float value) { speedChance = value; }
