/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 22:47:19 by ecoelho-          #+#    #+#             */
/*   Updated: 2025/05/02 22:48:53 by ecoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string name, Weapon& weapon) : _name(name), _weapon(weapon) {
	return ;
}

HumanA::~HumanA(void){
	return ;
}

void HumanA::attack(void) const {
    std::cout << _name << " attacks with their " << _weapon.getType() << std::endl; 
}