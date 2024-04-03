#include <iostream>

#include "move.h"
#include "pokemon.h"
#include "stats.h"

int main() {
  // Create some stats
  Stats pikachuStats(35, 55, 40, 90, 50);

  // Create some moves
  std::vector<Move> pikachuMoves;
  pikachuMoves.emplace_back("Thunder Shock", 40, 30);
  pikachuMoves.emplace_back("Quick Attack", 40, 30);
  pikachuMoves.emplace_back("Tail Whip", 0, 30);
  pikachuMoves.emplace_back("Thunder Wave", 0, 20);

  std::string name = "Pikachu";

  // Create a Pokemon with the stats and moves
  Pokemon pikachu(name, pikachuStats, pikachuMoves);

  // Output the Pokemon's name
  std::cout << "Pokemon: " << pikachu.getName() << std::endl;

  // Output the Pokemon's stats
  std::string hp = "hp";
  std::cout << "HP: " << pikachu.getStat(hp) << std::endl;

  // Output the Pokemon's moves
  std::vector<Move> moves = pikachu.getMoves();
  std::cout << "Moves:" << std::endl;
  for (const auto& move : moves) {
    std::cout << move.name << " - Damage: " << move.dmg << ", PP: " << move.pp
              << std::endl;
  }

  return 0;
}
