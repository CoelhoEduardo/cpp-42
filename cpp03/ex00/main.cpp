#include "ClapTrap.hpp"

int main() {
    std::cout << "--- ClapTrap Test ---" << std::endl;
    ClapTrap c("CL4P");
    c.attack("Enemy");
    c.takeDamage(5);
    c.takeDamage(10);
    c.takeDamage(5);
    c.beRepaired(3);

    return (0);
}
