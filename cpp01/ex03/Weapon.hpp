/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 22:46:17 by ecoelho-          #+#    #+#             */
/*   Updated: 2025/05/02 22:54:21 by ecoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>
#include <string>

class Weapon {
private:
    std::string _type; 				

public:
    Weapon(const std::string& type); 	
	~Weapon(void); 						
	
    const std::string& getType(void) const; 
    void setType(const std::string& type);
};

#endif
