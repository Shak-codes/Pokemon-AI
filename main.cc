#include <iostream>

#include "pokemon/constants/enums.h"
#include "pokemon/moves/move.h"
#include "pokemon/pokemon.h"
#include "pokemon/stats/stats.h"
#include "trainers/trainer.h"

int main() {
  // Create some stats
  Stats pikachuStats(35, 55, 40, 90, 50);

  Effect ThunderShock = Effect::STATUS;
  Effect QuickAttack = Effect::NONE;
  Effect TailWhip = Effect::DEBUFF;
  Effect ThunderWave = Effect::STATUS;

  // Create some moves
  std::vector<Move> pikachuMoves;
  pikachuMoves.emplace_back("Thunder Shock", 40, 30, ThunderShock);
  pikachuMoves.emplace_back("Quick Attack", 40, 30, QuickAttack);
  pikachuMoves.emplace_back("Tail Whip", 0, 30, TailWhip);
  pikachuMoves.emplace_back("Thunder Wave", 0, 20, ThunderWave);

  std::string name = "Pikachu";

  // Create a Pokemon with the stats and moves
  Pokemon* pikachu = new Pokemon(name, pikachuStats, pikachuMoves);

  // Output the Pokemon's name
  std::cout << "Pokemon: " << pikachu->getName() << std::endl;

  // Output the Pokemon's stats
  std::string hp = "hp";
  std::cout << "HP: " << pikachu->getStat(hp) << std::endl;

  // Output the Pokemon's moves
  std::vector<Move> moves = pikachu->getMoves();
  std::cout << "Moves:" << std::endl;
  for (const auto& move : moves) {
    std::cout << move.getName() << " - Damage: " << move.getDamage()
              << ", PP: " << move.getPP() << std::endl;
  }

  std::vector<Pokemon*> team = {pikachu};
  Trainer* Lance = new Trainer(TrainerClass::Lance, team);
  Lance->battle(Lance);
}
