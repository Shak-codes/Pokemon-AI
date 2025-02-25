#ifndef MULTISTRIKE
#define MULTISTRIKE

#include "../../../../lib/json.hpp"

using json = nlohmann::json;

class Multistrike {
 private:
  std::map<int, float> prob{};

 public:
  Multistrike(const json& effects);
  const std::map<int, float>& getProb() const;
  bool isMultistrike() const;
};

#endif
