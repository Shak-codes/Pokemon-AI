// Pokemon.cpp
#include "pokemon.h"

#include "constants/enums.h"

// Constructor
Pokemon::Pokemon(std::string& name, Stats stats, std::vector<Move> moves)
    : name(std::move(name)), stats(std::move(stats)), moves(std::move(moves)) {}

std::string Pokemon::getName() const { return name; }

std::vector<Type> Pokemon::getTypes() const { return types; }

Status Pokemon::getStatus() const { return status; }

int Pokemon::getStat(std::string& stat) const { return stats.getStat(stat); }

std::vector<Move> Pokemon::getMoves() const { return moves; }
