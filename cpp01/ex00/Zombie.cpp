#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name) {
    std::cout << "Zombie: " << _name << " created!" << std::endl;
}

Zombie::~Zombie() {
    std::cout << "Zombie: " << _name << " destructor!" << std::endl;
}

 void Zombie::announce() {
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
 }
 