/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 21:36:42 by ecoelho-          #+#    #+#             */
/*   Updated: 2025/10/31 10:10:19 by ecoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        std::cout << "-----------------" << std::endl;
        std::cout << "|  MOCK TEST'S  |" << std::endl;
        std::cout << "-----------------" << std::endl << std::endl;
        
        Bureaucrat bob("Bob", 1);
        Bureaucrat jim("Jim", 150);
        
        std::cout << "=== Test 1: Bob executed Shrubbery Creation (SUCCESS ✅) ===" << std::endl << std::endl;
        ShrubberyCreationForm shrub("home");
        bob.signForm(shrub);
        bob.executeForm(shrub);
        std::cout << std::endl;
        std::cout << "=== Test 2: Jim couldn't execute... Form is not signed yet (FAILED ❌) ===" << std::endl << std::endl;
        RobotomyRequestForm robot("Bender");
        jim.executeForm(robot);
        std::cout << std::endl;
        std::cout << "=== Test 3: Grade is not enough ===" << std::endl << std::endl;
        PresidentialPardonForm pardon("Arthur");
        bob.signForm(pardon);
        std::cout << std::endl;
        jim.executeForm(pardon);
        std::cout << std::endl;
        bob.executeForm(pardon);
        std::cout << std::endl;
        
    } catch (std::exception & e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}
    
