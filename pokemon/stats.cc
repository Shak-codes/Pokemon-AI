// Stats.cpp
#include "stats.h"

#include <stdexcept>

Stats::Stats(int hpValue, int atkValue, int defValue, int speValue,
             int spdValue)
    : hp(hpValue), atk(atkValue), def(defValue), spe(speValue), spd(spdValue) {}

int Stats::getStat(const std::string& statName) {
  if (statName == "hp")
    return hp;
  else if (statName == "atk")
    return atk;
  else if (statName == "def")
    return def;
  else if (statName == "spe")
    return spe;
  else if (statName == "spd")
    return spd;
  else
    throw std::invalid_argument("Unknown stat name");
}
