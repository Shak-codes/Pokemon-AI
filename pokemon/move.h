#ifndef __MOVE__
#define __MOVE__

#include <string>

class Move {
 public:
  Move(const std::string& name, int dmg, int pp);

  std::string name;
  int dmg;
  int pp;
};

#endif