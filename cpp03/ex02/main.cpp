#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    std::cout << "--- ClapTrap Test ---" << std::endl;
    ClapTrap c("CL4P");
    c.attack("Enemy");
    c.takeDamage(5);
    c.beRepaired(3);

    std::cout << "\n--- ScavTrap Test ---" << std::endl;
    ScavTrap s("SC4V");
    s.attack("Intruder");
    s.guardGate();
    s.takeDamage(20);
    s.beRepaired(10);

    std::cout << "\n--- FragTrap Test ---" << std::endl;
    FragTrap f("FR4G");
    f.attack("Boss");
    f.highFivesGuys();
    f.takeDamage(40);
    f.beRepaired(25);

    return 0;
}
