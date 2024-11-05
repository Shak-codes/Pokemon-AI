#include "stats.h"

Stats::Stats(int hpValue, int atkValue, int defValue, int speValue,
             int spdValue)
    : hp(hpValue), atk(atkValue), def(defValue), spe(speValue), spd(spdValue) {}

int Stats::getStat(const std::string& statName) const {
  if (statName == "hp")
    return hp;
  else if (statName == "atk")
    return atk;
  else if (statName == "def")
    return def;
  else if (statName == "spe")
    return spe;
  else
    return spd;
}
