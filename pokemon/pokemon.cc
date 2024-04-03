// Pokemon.cpp
#include "pokemon.h"

// Constructor
Pokemon::Pokemon(std::string& name, Stats stats, std::vector<Move> moves)
    : name(std::move(name)), stats(std::move(stats)), moves(std::move(moves)) {
  // The body is empty since all work is done by the member initializer list.
}

// Getter for the name
std::string Pokemon::getName() { return name; }

int Pokemon::getStat(std::string& stat) { return stats.getStat(stat); }

// Getter for the moves
std::vector<Move> Pokemon::getMoves() { return moves; }
