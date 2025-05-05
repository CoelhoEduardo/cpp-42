/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:14:45 by ecoelho-          #+#    #+#             */
/*   Updated: 2025/05/05 18:14:47 by ecoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

class Harl {
    private:
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
		void	(Harl::*ptr[5]) ( void );
    
    public:
		Harl(void);
		~Harl(void);
		
        void complain(std::string level);
};

#endif
