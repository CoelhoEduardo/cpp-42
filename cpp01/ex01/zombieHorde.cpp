#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name) {
  std::ostringstream index;
  int i = 0;
  Zombie *horde = new Zombie[N];

  while (i < N) {
    index.str("");
    index.clear();
    index << i;
    horde[i].setName(name + "-number-" + index.str());
    i++;
  }
  return horde;
}
