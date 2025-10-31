/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 18:13:43 by ecoelho-          #+#    #+#             */
/*   Updated: 2025/10/27 21:36:49 by ecoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class Form {
    private:
        const std::string _name;
        bool    _isSigned;
        const int   _gradeToSign;
        const int   _gradeToExecute;
    public:
        Form(const std::string &name, int gradeToSign, int gradeToExecute);
        Form(const Form &other);
        Form &operator=(const Form &other);
        ~Form();

        std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        void beSigned(const Bureaucrat &bureaucrat);

        class GradeTooHighException: public std::exception {
            public:
                virtual const char *what() const throw();
        };
        class GradeTooLowException: public std::exception {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif
