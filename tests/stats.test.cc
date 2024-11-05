#include "../pokemon/stats/stats.h"

#include <cassert>
#include <string>

int main() {
  Stats pokemon_stats = Stats(50, 40, 30, 20, 10);
  int hp = pokemon_stats.getStat("hp");
  int atk = pokemon_stats.getStat("atk");
  int def = pokemon_stats.getStat("def");
  int spe = pokemon_stats.getStat("spe");
  int spd = pokemon_stats.getStat("spd");

  assert(hp == 50 && ("Success! (hp stat)"));
  assert(atk == 40 && ("Success! (hp stat)"));
  assert(def == 30 && ("Success! (hp stat)"));
  assert(spe == 20 && ("Success! (hp stat)"));
  assert(spd == 10 && ("Success! (hp stat)"));
}