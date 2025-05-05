/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 22:46:40 by ecoelho-          #+#    #+#             */
/*   Updated: 2025/05/02 22:50:38 by ecoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
private:
    std::string _name;
    Weapon* _weapon;

public:
    HumanB(const std::string name);
	~HumanB(void);
	
    void setWeapon(Weapon& weapon);
    void attack(void) const;
};

#endif