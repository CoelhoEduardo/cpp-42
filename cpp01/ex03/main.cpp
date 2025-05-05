/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 22:40:24 by ecoelho-          #+#    #+#             */
/*   Updated: 2025/05/02 23:00:06 by ecoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main(void) {
  {
    Weapon weapon = Weapon("Iron hammer");
    HumanA character("Nate", weapon);
    character.attack();
    weapon.setType("shield");
    character.attack();
  }
  {
    Weapon weapon = Weapon("Desert Eagle");
    HumanB character2("Jonny");
    character2.setWeapon(weapon);
    character2.attack();
    weapon.setType("shotgun");
    character2.attack();
  }
  return (0);
}