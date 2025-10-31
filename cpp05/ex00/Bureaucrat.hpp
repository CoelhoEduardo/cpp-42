/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 21:37:03 by ecoelho-          #+#    #+#             */
/*   Updated: 2025/10/27 21:37:04 by ecoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat {
    private:
        const std::string _name;
        int _grade;
    public:
        Bureaucrat(const std::string &name, int _grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat();
        
        std::string getName() const;
        int getGrade() const;

        void increment();
        void decrement();

        class GradeTooHighException: public std::exception {
            public: 
            virtual const char *what() const throw();
        };

        class GradeTooLowException: public std::exception {
            public: 
            virtual const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif
