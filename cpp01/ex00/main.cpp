#include "Zombie.hpp"

void testNewZombie() {
    Zombie* zombie = newZombie("Eduuuardooo");

    zombie->announce();

    delete zombie;
}

void testRandomChump() {
    randomChump("Random");
}

int main() {
    testNewZombie();

    testRandomChump();

    return 0;
}
