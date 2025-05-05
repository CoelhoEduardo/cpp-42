#include "Zombie.hpp"


Zombie::Zombie(void) {
    return;
}

Zombie::~Zombie(void) {
    std::cout << this->_name << " Delete zombie" << std::endl << std::endl;
}

void Zombie::setName(std::string name) {
    this->_name = name;
}

void Zombie::announce(void) {
    std::cout << this->_name << " Construct zombie" << std::endl << std::endl;
}
