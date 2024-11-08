// Move.cpp
#include "move.h"

#include "../constants/enums.h"

Move::Move(const std::string& name, Type type, int dmg, int pp, Effect effect)
    : name(name), type(type), dmg(dmg), pp(pp), effect(effect) {}

std::string Move::getName() const { return name; }

Type Move::getType() const { return type; }

int Move::getDamage() const { return dmg; }

int Move::getPP() const { return pp; }

Effect Move::getEffect() const { return effect; }

bool Move::pureStatus() const { return effect == Effect::STATUS && dmg == 0; }

bool Move::isBuff() const { return effect == Effect::BUFF; }

bool Move::isDebuff() const { return effect == Effect::DEBUFF; }