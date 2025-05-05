/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:14:37 by ecoelho-          #+#    #+#             */
/*   Updated: 2025/05/05 18:14:39 by ecoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl		Harl;

	if (argc == 2)
		Harl.complain(argv[1]);
	else if (argc < 2)
		std::cerr << "Error! No input has given" << std::endl;
	else
		std::cerr << "Please one input(complain level) at a time!" << std::endl;
	return (0);
}
