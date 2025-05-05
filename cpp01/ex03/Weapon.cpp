/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 22:46:29 by ecoelho-          #+#    #+#             */
/*   Updated: 2025/05/02 22:50:16 by ecoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& type) : _type(type) {
	return ;
}

Weapon::~Weapon(void) {
	return ;
}

const std::string& Weapon::getType(void) const {
    return _type;
}

void Weapon::setType(const std::string& type) {
    this->_type = type;
}
