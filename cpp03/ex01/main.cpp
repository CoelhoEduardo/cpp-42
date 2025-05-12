#include "ScavTrap.hpp"

int main() {
    std::cout << "--- ClapTrap Test ---" << std::endl;
    ClapTrap c("CL4P");
    c.attack("Enemy");
    c.takeDamage(5);
    c.beRepaired(3);

    std::cout << "\n--- ScavTrap Test ---" << std::endl;
    ScavTrap s1("SC4V");
    s1.attack("Intruder");
    s1.guardGate();
    s1.takeDamage(20);
    s1.beRepaired(10);

    std::cout << "\n--- ScavTrap Copy Test ---" << std::endl;
    ScavTrap s2 = s1;  // Copy constructor
    s2.attack("Another Target");

    std::cout << "\n--- ScavTrap Multiple Actions Test ---" << std::endl;
    ScavTrap s3("GUARD-BOT");
    for (int i = 0; i < 6; ++i) {
        s3.attack("Enemy");
    }
    s3.guardGate();

    return 0;
}
