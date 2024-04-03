#ifndef __POKEMON__

#include <string>
#include <vector>

struct PokemonStats {
  PokemonStats(int hpValue, int atkValue, int defValue, int speValue,
               int spdValue)
      : hp(hpValue),
        atk(atkValue),
        def(defValue),
        spe(speValue),
        spd(spdValue) {}
  int hp;
  int atk;
  int def;
  int spe;
  int spd;
};

struct Move {
  Move(const std::string& name, int dmg, int pp)
      : name(name), dmg(dmg), pp(pp) {}

  std::string name;
  int dmg;
  int pp;
};

struct PokemonMoves {
  std::vector<Move> moves;

  PokemonMoves(std::initializer_list<Move> initList) : moves(initList) {}
};

class Pokemon {
 private:
  std::string name;
  PokemonStats stats;
  PokemonMoves moves;

 public:
  std::string getName();
  int getStat();
  PokemonMoves getMoves();
};

#endif