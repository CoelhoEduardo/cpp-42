/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 21:36:42 by ecoelho-          #+#    #+#             */
/*   Updated: 2025/11/10 12:30:44 by ecoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main() {
    Intern intern;
    Bureaucrat boss("Boss", 1);

    std::cout << "-----------------" << std::endl;
    std::cout << "|  MOCK TEST'S  |" << std::endl;
    std::cout << "-----------------" << std::endl << std::endl;
    
    std::cout << "\n=== Test 1: Creating Shrubbery ===\n";
    try {
        AForm* form1 = intern.makeForm("shrubbery creation", "home");
        boss.signForm(*form1);
        boss.executeForm(*form1);
        delete form1;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== Test 2: Creating Robotomy ===\n";
    try {
        AForm* form2 = intern.makeForm("robotomy request", "Bender");
        boss.signForm(*form2);
        boss.executeForm(*form2);
        delete form2;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== Test 3: Creating Presidential Pardon ===\n";
    try {
        AForm* form3 = intern.makeForm("presidential pardon", "Arthur Dent");
        boss.signForm(*form3);
        boss.executeForm(*form3);
        delete form3;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== Test 4: Unknown Form ===\n";
    try {
        AForm* form4 = intern.makeForm("tax evasion", "Trump");
        delete form4;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}
    
