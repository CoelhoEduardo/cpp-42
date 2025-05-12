#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("FragDefault") {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap Default constructed!" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap " << _name << " constructed!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "FragTrap " << _name << " copied - cloning complete!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
        std::cout << "FragTrap " << _name << " assigned - system update successful!" << std::endl;
    }
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << _name << " shutting down... Goodbye!" << std::endl;
}


void FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << _name << " wants high fives! ✋" << std::endl;
}
