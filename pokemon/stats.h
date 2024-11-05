#ifndef __STATS__
#define __STATS__

#include <string>

class Stats {
  int hp;
  int atk;
  int def;
  int spe;
  int spd;

 public:
  Stats(int hpValue, int atkValue, int defValue, int speValue, int spdValue);
  int getStat(const std::string& statName) const;
};

#endif