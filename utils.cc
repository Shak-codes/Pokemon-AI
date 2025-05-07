#include <random>

int random(unsigned int seed, int min = 1, int max = 64) {
  std::mt19937 gen(seed);
  std::uniform_int_distribution<> distrib(min, max);
  return distrib(gen);
}
