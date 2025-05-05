/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 22:47:04 by ecoelho-          #+#    #+#             */
/*   Updated: 2025/05/02 22:50:27 by ecoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
private:
    std::string _name;
    Weapon& _weapon;

public:
    HumanA(const std::string name, Weapon& weapon);
	~HumanA(void);
	
    void attack(void) const;
};

#endif