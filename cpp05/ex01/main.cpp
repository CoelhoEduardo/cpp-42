/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 21:36:42 by ecoelho-          #+#    #+#             */
/*   Updated: 2025/10/27 21:36:44 by ecoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {

        std::cout << "-----------------" << std::endl;
        std::cout << "|  MOCK TEST'S  |" << std::endl;
        std::cout << "-----------------" << std::endl << std::endl;

        std::cout << "=== Test 1: Bureaucrat with grade to sign form (SUCCESS ✅) ===" << std::endl << std::endl;
        Bureaucrat alice("Alice", 30);
        Form form1("Important Document", 50, 25);
        
        std::cout << alice << std::endl << std::endl;
        alice.signForm(form1);
        std::cout << form1 << std::endl << std::endl;

        std::cout << "------------------------------------------------------------------------------------" << std::endl << std::endl;
        
        std::cout << "=== Test 2: Bureaucrat with no grade to sign form (FAILED ❌) ===" << std::endl << std::endl;
        Bureaucrat bob("Bob", 100);
        Form form2("Top Secret", 50, 25);

        std::cout << bob << std::endl << std::endl;
        bob.signForm(form2);
        std::cout << form2 << std::endl << std::endl;
        
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    return (0);
}
