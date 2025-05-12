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
    std::cout << "ScavTrap " << _name << " copied!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    std::cout << "ScavTrap " << _name << " assigned!" << std::endl;
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << _name << " destroyed!" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (_energyPoints > 0 && _hitPoints > 0) {
        _energyPoints--;
        std::cout << "ScavTrap " << _name << " launches a special attack on " << target << ", dealing " << _attackDamage << " points of epic damage!" << std::endl;
    } else {
        std::cout << "ScavTrap " << _name << " is too exhausted to attack!" << std::endl;
    }
}

void ScavTrap::guardGate() {
    if (_hitPoints > 0) {
        std::cout << "ScavTrap " << _name << " has entered the prestigious Gate keeper mode!" << std::endl;
    } else {
        std::cout << "ScavTrap " << _name << " cannot enter Gate keeper mode - system offline!" << std::endl;
    }
}
