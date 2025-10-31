/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 21:36:59 by ecoelho-          #+#    #+#             */
/*   Updated: 2025/10/27 21:37:00 by ecoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    std::cout << "-----------------" << std::endl;
    std::cout << "|  MOCK TEST'S  |" << std::endl;
    std::cout << "-----------------" << std::endl << std::endl;

    Bureaucrat b1("Eduardo", 150);
    Bureaucrat b2("John", 1);

    std::cout << "Testing to Low Exeception" << std::endl << std::endl;
    b1.decrement();
    std::cout << b1 << std::endl << std::endl;
    
    std::cout << "--------------" << std::endl << std::endl;
    
    std::cout << "Testing to High Exeception" << std::endl << std::endl;
    b2.increment();
    std::cout << b2 << std::endl << std::endl ;
    
    std::cout << "--------------" << std::endl << std::endl;
    
    std::cout << "Increment test" << std::endl << std::endl;
    std::cout << b1 << std::endl;
    b1.increment();
    std::cout << b1 << std::endl << std::endl;
    
    std::cout << "--------------" << std::endl << std::endl;
    
    std::cout << "Decrement test" << std::endl << std::endl;
    std::cout << b2 << std::endl;
    b2.decrement();
    std::cout << b2 << std::endl << std::endl;

    std::cout << "--------------" << std::endl << std::endl;

    return (0);
}