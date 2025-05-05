/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 22:46:51 by ecoelho-          #+#    #+#             */
/*   Updated: 2025/05/02 22:52:41 by ecoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string name) : _name(name), _weapon(NULL) {
	return ;
}

HumanB::~HumanB(void) {
	return ;
}

void HumanB::setWeapon(Weapon& weapon) {
    this->_weapon = &weapon; 
}

void HumanB::attack(void) const {
    if (_weapon) {
        std::cout << _name << " attacks with their " << _weapon->getType() << std::endl; 
    } else {
        std::cout << _name << " attacks with their bare hands" << std::endl;
    }
}