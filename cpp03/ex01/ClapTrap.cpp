#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap Deafault constructed!" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap " << _name << " constructed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
    *this = other;
    std::cout << "ClapTrap " << _name << " copied!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this != &other) {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << _name << " destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (_energyPoints > 0 && _hitPoints > 0) {
        _energyPoints--;
        std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
    } else {
        std::cout << "ClapTrap " << _name << " can't attack! No energy or HP." << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (_hitPoints == 0) {
        std::cout << "ClapTrap " << _name << " is already destroyed!" << std::endl;
        return;
    }
    
    _hitPoints = std::max(0, _hitPoints - static_cast<int>(amount));
    std::cout << "ClapTrap " << _name << " takes " << amount << " damage! Remaining HP: " << _hitPoints << std::endl;

    if (_hitPoints == 0) {
        std::cout << "ClapTrap " << _name << " has been destroyed!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_energyPoints > 0 && _hitPoints > 0) {
        _energyPoints--;
        _hitPoints = std::min(_hitPoints + static_cast<int>(amount), 10);
        std::cout << "ClapTrap " << _name << " repairs itself, gaining " << amount << " HP!" << std::endl;
    } else {
        std::cout << "ClapTrap " << _name << " can't repair!" << std::endl;
    }
}
