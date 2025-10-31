/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 18:13:43 by ecoelho-          #+#    #+#             */
/*   Updated: 2025/10/30 22:59:59 by ecoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm {
    private:
        const std::string _name;
        bool    _isSigned;
        const int   _gradeToSign;
        const int   _gradeToExecute;
        const std::string _target;
    protected:

    virtual void executeAction() const = 0;

    public:
        AForm(const std::string &name, int gradeToSign, int gradeToExecute, const std::string &target);
        AForm(const AForm &other);
        AForm &operator=(const AForm &other);
        virtual ~AForm();

        std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        std::string getTarget() const;

        void beSigned(const Bureaucrat &bureaucrat);
        void execute(Bureaucrat const &executor) const;

        class GradeTooHighException: public std::exception {
            public:
                virtual const char *what() const throw();
        };
        class GradeTooLowException: public std::exception {
            public:
                virtual const char *what() const throw();
        };
        class FormNotSignedException: public std::exception {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif
