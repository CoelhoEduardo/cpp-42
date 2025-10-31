/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 21:36:42 by ecoelho-          #+#    #+#             */
/*   Updated: 2025/10/30 22:55:49 by ecoelho-         ###   ########.fr       */
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
        
        Bureaucrat bob("Bob", 1);      // Super poderoso
        Bureaucrat jim("Jim", 150);    // Fraquinho
        
        ShrubberyCreationForm shrub("home");
        
        // Cenário 1: Sucesso
        bob.signForm(shrub);
        bob.executeForm(shrub);  // ✅ "Bob executed Shrubbery Creation"
        
        // Cenário 2: Não assinado
        RobotomyRequestForm robot("Bender");
        jim.executeForm(robot);  // ❌ "Jim couldn't execute... Form is not signed yet"
        
        // Cenário 3: Grade insuficiente
        PresidentialPardonForm pardon("Arthur");
        bob.signForm(pardon);
        jim.executeForm(pardon);  // ❌ "Jim couldn't execute... grade too low"
        bob.executeForm(pardon);  // ✅ "Bob executed Presidential Pardon"
        
    } catch (std::exception & e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}
    
