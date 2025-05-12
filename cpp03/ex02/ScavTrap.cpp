#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("ScavDefault") {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap Default constructed!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << _name << " constructed!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << "ScavTrap copied!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    ClapTrap::operator=(other);
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << _name << " destroyed!" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    std::cout << "ScavTrap " << _name << " ferociously attacks " << target << ", causing " << _attackDamage << " damage!" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode!" << std::endl;
}

