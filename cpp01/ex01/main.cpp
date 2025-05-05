#include "Zombie.hpp"

int main() {
    int numberOfZombies = 100;
    std::string name = "Bozo";

    Zombie* horde = zombieHorde(numberOfZombies, name);


    for (int i = 0; numberOfZombies > i; i++) {
        horde[i].announce();
    }

    delete[] horde;
    
    return (0);
}