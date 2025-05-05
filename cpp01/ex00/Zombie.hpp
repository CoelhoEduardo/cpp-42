/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:38:00 by ecoelho-          #+#    #+#             */
/*   Updated: 2025/05/02 22:01:43 by ecoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
public:
  Zombie(std::string name);
  ~Zombie();
  void announce(void);

private:
  std::string _name;
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif