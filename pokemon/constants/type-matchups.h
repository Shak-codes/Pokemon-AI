#ifndef __MATCHUPS__
#define __MATCHUPS__

#include <map>

#include "enums.h"

std::map<std::pair<Type, Type>, double> typeMatchups = {
    // NORMAL
    {{Type::Normal, Type::Normal}, 1.0},
    {{Type::Normal, Type::Fighting}, 1.0},
    {{Type::Normal, Type::Flying}, 1.0},
    {{Type::Normal, Type::Poison}, 1.0},
    {{Type::Normal, Type::Ground}, 1.0},
    {{Type::Normal, Type::Rock}, 1.0},
    {{Type::Normal, Type::Bug}, 1.0},
    {{Type::Normal, Type::Ghost}, 0.0},
    {{Type::Normal, Type::Steel}, 1.0},
    {{Type::Normal, Type::Fire}, 1.0},
    {{Type::Normal, Type::Water}, 1.0},
    {{Type::Normal, Type::Grass}, 1.0},
    {{Type::Normal, Type::Electric}, 1.0},
    {{Type::Normal, Type::Psychic}, 1.0},
    {{Type::Normal, Type::Ice}, 1.0},
    {{Type::Normal, Type::Dragon}, 1.0},
    {{Type::Normal, Type::Dark}, 1.0},
    {{Type::Normal, Type::Fairy}, 1.0},
    // FIGHTING
    {{Type::Fighting, Type::Normal}, 2.0},
    {{Type::Fighting, Type::Fighting}, 1.0},
    {{Type::Fighting, Type::Flying}, 0.5},
    {{Type::Fighting, Type::Poison}, 0.5},
    {{Type::Fighting, Type::Ground}, 1.0},
    {{Type::Fighting, Type::Rock}, 2.0},
    {{Type::Fighting, Type::Bug}, 0.5},
    {{Type::Fighting, Type::Ghost}, 0.0},
    {{Type::Fighting, Type::Steel}, 2.0},
    {{Type::Fighting, Type::Fire}, 1.0},
    {{Type::Fighting, Type::Water}, 1.0},
    {{Type::Fighting, Type::Grass}, 1.0},
    {{Type::Fighting, Type::Electric}, 1.0},
    {{Type::Fighting, Type::Psychic}, 2.0},
    {{Type::Fighting, Type::Ice}, 2.0},
    {{Type::Fighting, Type::Dragon}, 1.0},
    {{Type::Fighting, Type::Dark}, 2.0},
    {{Type::Fighting, Type::Fairy}, 0.5},
    // FLYING
    {{Type::Flying, Type::Normal}, 1.0},
    {{Type::Flying, Type::Fighting}, 2.0},
    {{Type::Flying, Type::Flying}, 1.0},
    {{Type::Flying, Type::Poison}, 1.0},
    {{Type::Flying, Type::Ground}, 1.0},
    {{Type::Flying, Type::Rock}, 2.0},
    {{Type::Flying, Type::Bug}, 2.0},
    {{Type::Flying, Type::Ghost}, 1.0},
    {{Type::Flying, Type::Steel}, 1.0},
    {{Type::Flying, Type::Fire}, 1.0},
    {{Type::Flying, Type::Water}, 1.0},
    {{Type::Flying, Type::Grass}, 2.0},
    {{Type::Flying, Type::Electric}, 0.5},
    {{Type::Flying, Type::Psychic}, 1.0},
    {{Type::Flying, Type::Ice}, 2.0},
    {{Type::Flying, Type::Dragon}, 1.0},
    {{Type::Flying, Type::Dark}, 1.0},
    {{Type::Flying, Type::Fairy}, 1.0},
    // POISON
    {{Type::Poison, Type::Normal}, 1.0},
    {{Type::Poison, Type::Fighting}, 0.5},
    {{Type::Poison, Type::Flying}, 1.0},
    {{Type::Poison, Type::Poison}, 0.5},
    {{Type::Poison, Type::Ground}, 2.0},
    {{Type::Poison, Type::Rock}, 0.5},
    {{Type::Poison, Type::Bug}, 1.0},
    {{Type::Poison, Type::Ghost}, 0.5},
    {{Type::Poison, Type::Steel}, 0.0},
    {{Type::Poison, Type::Fire}, 1.0},
    {{Type::Poison, Type::Water}, 1.0},
    {{Type::Poison, Type::Grass}, 0.5},
    {{Type::Poison, Type::Electric}, 1.0},
    {{Type::Poison, Type::Psychic}, 1.0},
    {{Type::Poison, Type::Ice}, 1.0},
    {{Type::Poison, Type::Dragon}, 1.0},
    {{Type::Poison, Type::Dark}, 1.0},
    {{Type::Poison, Type::Fairy}, 2.0},
    // GROUND
    {{Type::Ground, Type::Normal}, 1.0},
    {{Type::Ground, Type::Fighting}, 1.0},
    {{Type::Ground, Type::Flying}, 0.0},
    {{Type::Ground, Type::Poison}, 2.0},
    {{Type::Ground, Type::Ground}, 1.0},
    {{Type::Ground, Type::Rock}, 2.0},
    {{Type::Ground, Type::Bug}, 0.5},
    {{Type::Ground, Type::Ghost}, 1.0},
    {{Type::Ground, Type::Steel}, 2.0},
    {{Type::Ground, Type::Fire}, 2.0},
    {{Type::Ground, Type::Water}, 1.0},
    {{Type::Ground, Type::Grass}, 0.5},
    {{Type::Ground, Type::Electric}, 2.0},
    {{Type::Ground, Type::Psychic}, 1.0},
    {{Type::Ground, Type::Ice}, 1.0},
    {{Type::Ground, Type::Dragon}, 1.0},
    {{Type::Ground, Type::Dark}, 1.0},
    {{Type::Ground, Type::Fairy}, 1.0},
    // ROCK
    {{Type::Rock, Type::Normal}, 1.0},
    {{Type::Rock, Type::Fighting}, 2.0},
    {{Type::Rock, Type::Flying}, 0.5},
    {{Type::Rock, Type::Poison}, 1.0},
    {{Type::Rock, Type::Ground}, 2.0},
    {{Type::Rock, Type::Rock}, 1.0},
    {{Type::Rock, Type::Bug}, 2.0},
    {{Type::Rock, Type::Ghost}, 1.0},
    {{Type::Rock, Type::Steel}, 0.5},
    {{Type::Rock, Type::Fire}, 0.5},
    {{Type::Rock, Type::Water}, 2.0},
    {{Type::Rock, Type::Grass}, 2.0},
    {{Type::Rock, Type::Electric}, 1.0},
    {{Type::Rock, Type::Psychic}, 1.0},
    {{Type::Rock, Type::Ice}, 1.0},
    {{Type::Rock, Type::Dragon}, 1.0},
    {{Type::Rock, Type::Dark}, 1.0},
    {{Type::Rock, Type::Fairy}, 1.0},
    // BUG
    {{Type::Bug, Type::Normal}, 1.0},
    {{Type::Bug, Type::Fighting}, 0.5},
    {{Type::Bug, Type::Flying}, 2.0},
    {{Type::Bug, Type::Poison}, 1.0},
    {{Type::Bug, Type::Ground}, 0.5},
    {{Type::Bug, Type::Rock}, 2.0},
    {{Type::Bug, Type::Bug}, 1.0},
    {{Type::Bug, Type::Ghost}, 0.5},
    {{Type::Bug, Type::Steel}, 0.5},
    {{Type::Bug, Type::Fire}, 2.0},
    {{Type::Bug, Type::Water}, 1.0},
    {{Type::Bug, Type::Grass}, 0.5},
    {{Type::Bug, Type::Electric}, 1.0},
    {{Type::Bug, Type::Psychic}, 2.0},
    {{Type::Bug, Type::Ice}, 1.0},
    {{Type::Bug, Type::Dragon}, 1.0},
    {{Type::Bug, Type::Dark}, 2.0},
    {{Type::Bug, Type::Fairy}, 0.5},
    // GHOST
    {{Type::Ghost, Type::Normal}, 0.0},
    {{Type::Ghost, Type::Fighting}, 0.0},
    {{Type::Ghost, Type::Flying}, 1.0},
    {{Type::Ghost, Type::Poison}, 0.5},
    {{Type::Ghost, Type::Ground}, 1.0},
    {{Type::Ghost, Type::Rock}, 1.0},
    {{Type::Ghost, Type::Bug}, 0.5},
    {{Type::Ghost, Type::Ghost}, 2.0},
    {{Type::Ghost, Type::Steel}, 0.5},
    {{Type::Ghost, Type::Fire}, 1.0},
    {{Type::Ghost, Type::Water}, 1.0},
    {{Type::Ghost, Type::Grass}, 1.0},
    {{Type::Ghost, Type::Electric}, 1.0},
    {{Type::Ghost, Type::Psychic}, 2.0},
    {{Type::Ghost, Type::Ice}, 1.0},
    {{Type::Ghost, Type::Dragon}, 1.0},
    {{Type::Ghost, Type::Dark}, 2.0},
    {{Type::Ghost, Type::Fairy}, 1.0},
    // STEEL
    {{Type::Steel, Type::Normal}, 0.5},
    {{Type::Steel, Type::Fighting}, 2.0},
    {{Type::Steel, Type::Flying}, 0.5},
    {{Type::Steel, Type::Poison}, 0.0},
    {{Type::Steel, Type::Ground}, 2.0},
    {{Type::Steel, Type::Rock}, 0.5},
    {{Type::Steel, Type::Bug}, 0.5},
    {{Type::Steel, Type::Ghost}, 0.5},
    {{Type::Steel, Type::Steel}, 0.5},
    {{Type::Steel, Type::Fire}, 2.0},
    {{Type::Steel, Type::Water}, 1.0},
    {{Type::Steel, Type::Grass}, 0.5},
    {{Type::Steel, Type::Electric}, 1.0},
    {{Type::Steel, Type::Psychic}, 0.5},
    {{Type::Steel, Type::Ice}, 0.5},
    {{Type::Steel, Type::Dragon}, 0.5},
    {{Type::Steel, Type::Dark}, 0.5},
    {{Type::Steel, Type::Fairy}, 0.5},
    // FIRE
    {{Type::Fire, Type::Normal}, 1.0},
    {{Type::Fire, Type::Fighting}, 1.0},
    {{Type::Fire, Type::Flying}, 1.0},
    {{Type::Fire, Type::Poison}, 1.0},
    {{Type::Fire, Type::Ground}, 1.0},
    {{Type::Fire, Type::Rock}, 0.5},
    {{Type::Fire, Type::Bug}, 2.0},
    {{Type::Fire, Type::Ghost}, 1.0},
    {{Type::Fire, Type::Steel}, 0.5},
    {{Type::Fire, Type::Fire}, 0.5},
    {{Type::Fire, Type::Water}, 0.5},
    {{Type::Fire, Type::Grass}, 2.0},
    {{Type::Fire, Type::Electric}, 1.0},
    {{Type::Fire, Type::Psychic}, 1.0},
    {{Type::Fire, Type::Ice}, 2.0},
    {{Type::Fire, Type::Dragon}, 0.5},
    {{Type::Fire, Type::Dark}, 1.0},
    {{Type::Fire, Type::Fairy}, 1.0},
    // WATER
    {{Type::Water, Type::Normal}, 1.0},
    {{Type::Water, Type::Fighting}, 1.0},
    {{Type::Water, Type::Flying}, 1.0},
    {{Type::Water, Type::Poison}, 1.0},
    {{Type::Water, Type::Ground}, 2.0},
    {{Type::Water, Type::Rock}, 2.0},
    {{Type::Water, Type::Bug}, 1.0},
    {{Type::Water, Type::Ghost}, 1.0},
    {{Type::Water, Type::Steel}, 0.5},
    {{Type::Water, Type::Fire}, 2.0},
    {{Type::Water, Type::Water}, 0.5},
    {{Type::Water, Type::Grass}, 0.5},
    {{Type::Water, Type::Electric}, 1.0},
    {{Type::Water, Type::Psychic}, 1.0},
    {{Type::Water, Type::Ice}, 0.5},
    {{Type::Water, Type::Dragon}, 0.5},
    {{Type::Water, Type::Dark}, 1.0},
    {{Type::Water, Type::Fairy}, 1.0},
    // GRASS
    {{Type::Grass, Type::Normal}, 1.0},
    {{Type::Grass, Type::Fighting}, 1.0},
    {{Type::Grass, Type::Flying}, 0.5},
    {{Type::Grass, Type::Poison}, 2.0},
    {{Type::Grass, Type::Ground}, 0.5},
    {{Type::Grass, Type::Rock}, 2.0},
    {{Type::Grass, Type::Bug}, 2.0},
    {{Type::Grass, Type::Ghost}, 1.0},
    {{Type::Grass, Type::Steel}, 0.5},
    {{Type::Grass, Type::Fire}, 0.5},
    {{Type::Grass, Type::Water}, 2.0},
    {{Type::Grass, Type::Grass}, 0.5},
    {{Type::Grass, Type::Electric}, 1.0},
    {{Type::Grass, Type::Psychic}, 1.0},
    {{Type::Grass, Type::Ice}, 1.0},
    {{Type::Grass, Type::Dragon}, 0.5},
    {{Type::Grass, Type::Dark}, 1.0},
    {{Type::Grass, Type::Fairy}, 1.0},
    // ELECTRIC
    {{Type::Electric, Type::Normal}, 1.0},
    {{Type::Electric, Type::Fighting}, 1.0},
    {{Type::Electric, Type::Flying}, 2.0},
    {{Type::Electric, Type::Poison}, 1.0},
    {{Type::Electric, Type::Ground}, 0.0},
    {{Type::Electric, Type::Rock}, 1.0},
    {{Type::Electric, Type::Bug}, 1.0},
    {{Type::Electric, Type::Ghost}, 1.0},
    {{Type::Electric, Type::Steel}, 1.0},
    {{Type::Electric, Type::Fire}, 1.0},
    {{Type::Electric, Type::Water}, 2.0},
    {{Type::Electric, Type::Grass}, 0.5},
    {{Type::Electric, Type::Electric}, 0.5},
    {{Type::Electric, Type::Psychic}, 1.0},
    {{Type::Electric, Type::Ice}, 1.0},
    {{Type::Electric, Type::Dragon}, 0.5},
    {{Type::Electric, Type::Dark}, 1.0},
    {{Type::Electric, Type::Fairy}, 1.0},
    // PSYCHIC
    {{Type::Psychic, Type::Normal}, 1.0},
    {{Type::Psychic, Type::Fighting}, 2.0},
    {{Type::Psychic, Type::Flying}, 1.0},
    {{Type::Psychic, Type::Poison}, 1.0},
    {{Type::Psychic, Type::Ground}, 1.0},
    {{Type::Psychic, Type::Rock}, 1.0},
    {{Type::Psychic, Type::Bug}, 1.0},
    {{Type::Psychic, Type::Ghost}, 1.0},
    {{Type::Psychic, Type::Steel}, 0.5},
    {{Type::Psychic, Type::Fire}, 1.0},
    {{Type::Psychic, Type::Water}, 1.0},
    {{Type::Psychic, Type::Grass}, 1.0},
    {{Type::Psychic, Type::Electric}, 1.0},
    {{Type::Psychic, Type::Psychic}, 0.5},
    {{Type::Psychic, Type::Ice}, 1.0},
    {{Type::Psychic, Type::Dragon}, 1.0},
    {{Type::Psychic, Type::Dark}, 0.0},
    {{Type::Psychic, Type::Fairy}, 1.0},
    // ICE
    {{Type::Ice, Type::Normal}, 1.0},
    {{Type::Ice, Type::Fighting}, 1.0},
    {{Type::Ice, Type::Flying}, 2.0},
    {{Type::Ice, Type::Poison}, 1.0},
    {{Type::Ice, Type::Ground}, 2.0},
    {{Type::Ice, Type::Rock}, 1.0},
    {{Type::Ice, Type::Bug}, 1.0},
    {{Type::Ice, Type::Ghost}, 1.0},
    {{Type::Ice, Type::Steel}, 0.5},
    {{Type::Ice, Type::Fire}, 0.5},
    {{Type::Ice, Type::Water}, 0.5},
    {{Type::Ice, Type::Grass}, 2.0},
    {{Type::Ice, Type::Electric}, 1.0},
    {{Type::Ice, Type::Psychic}, 1.0},
    {{Type::Ice, Type::Ice}, 0.5},
    {{Type::Ice, Type::Dragon}, 2.0},
    {{Type::Ice, Type::Dark}, 1.0},
    {{Type::Ice, Type::Fairy}, 1.0},
    // DRAGON
    {{Type::Dragon, Type::Normal}, 1.0},
    {{Type::Dragon, Type::Fighting}, 1.0},
    {{Type::Dragon, Type::Flying}, 1.0},
    {{Type::Dragon, Type::Poison}, 1.0},
    {{Type::Dragon, Type::Ground}, 1.0},
    {{Type::Dragon, Type::Rock}, 1.0},
    {{Type::Dragon, Type::Bug}, 1.0},
    {{Type::Dragon, Type::Ghost}, 1.0},
    {{Type::Dragon, Type::Steel}, 0.5},
    {{Type::Dragon, Type::Fire}, 0.5},
    {{Type::Dragon, Type::Water}, 0.5},
    {{Type::Dragon, Type::Grass}, 0.5},
    {{Type::Dragon, Type::Electric}, 0.5},
    {{Type::Dragon, Type::Psychic}, 1.0},
    {{Type::Dragon, Type::Ice}, 2.0},
    {{Type::Dragon, Type::Dragon}, 2.0},
    {{Type::Dragon, Type::Dark}, 1.0},
    {{Type::Dragon, Type::Fairy}, 2.0},
    // DARK
    {{Type::Dark, Type::Normal}, 1.0},
    {{Type::Dark, Type::Fighting}, 0.5},
    {{Type::Dark, Type::Flying}, 1.0},
    {{Type::Dark, Type::Poison}, 1.0},
    {{Type::Dark, Type::Ground}, 1.0},
    {{Type::Dark, Type::Rock}, 1.0},
    {{Type::Dark, Type::Bug}, 1.0},
    {{Type::Dark, Type::Ghost}, 2.0},
    {{Type::Dark, Type::Steel}, 1.0},
    {{Type::Dark, Type::Fire}, 1.0},
    {{Type::Dark, Type::Water}, 1.0},
    {{Type::Dark, Type::Grass}, 1.0},
    {{Type::Dark, Type::Electric}, 1.0},
    {{Type::Dark, Type::Psychic}, 0.0},
    {{Type::Dark, Type::Ice}, 1.0},
    {{Type::Dark, Type::Dragon}, 1.0},
    {{Type::Dark, Type::Dark}, 0.5},
    {{Type::Dark, Type::Fairy}, 0.5},
    // FAIRY
    {{Type::Fairy, Type::Normal}, 1.0},
    {{Type::Fairy, Type::Fighting}, 2.0},
    {{Type::Fairy, Type::Flying}, 1.0},
    {{Type::Fairy, Type::Poison}, 0.5},
    {{Type::Fairy, Type::Ground}, 1.0},
    {{Type::Fairy, Type::Rock}, 1.0},
    {{Type::Fairy, Type::Bug}, 1.0},
    {{Type::Fairy, Type::Ghost}, 1.0},
    {{Type::Fairy, Type::Steel}, 0.5},
    {{Type::Fairy, Type::Fire}, 0.5},
    {{Type::Fairy, Type::Water}, 1.0},
    {{Type::Fairy, Type::Grass}, 1.0},
    {{Type::Fairy, Type::Electric}, 1.0},
    {{Type::Fairy, Type::Psychic}, 1.0},
    {{Type::Fairy, Type::Ice}, 1.0},
    {{Type::Fairy, Type::Dragon}, 2.0},
    {{Type::Fairy, Type::Dark}, 2.0},
    {{Type::Fairy, Type::Fairy}, 1.0}};

#endif