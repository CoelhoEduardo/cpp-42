/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:14:55 by ecoelho-          #+#    #+#             */
/*   Updated: 2025/05/05 18:16:06 by ecoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	ptr[0] = &Harl::debug;
	ptr[1] = &Harl::info;
	ptr[2] = &Harl::warning;
	ptr[3] = &Harl::error;
	return ;
}

Harl::~Harl(void)
{
	return ;
}

void Harl::debug(void) {
    std::cout << "DEBUG: I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n";
}

void Harl::info(void) {
    std::cout << "INFO: I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void Harl::warning(void) {
    std::cout << "WARNING: I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
}

void Harl::error(void) {
    std::cout << "ERROR: This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain(std::string level) {
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    
    int i = 0;
    while (i < 4 && level.compare(levels[i])) {
        i++;
    }
    
    if (i < 4) {
        (this->*ptr[i])();
    } else {
        std::cout << "Invalid level!\n";
    }
}