/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 18:13:59 by ecoelho-          #+#    #+#             */
/*   Updated: 2025/10/30 21:37:25 by ecoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
    {
        if ((gradeToSign < 1 || gradeToExecute < 1) && (gradeToSign > 150 || gradeToExecute > 150))
        {
            throw GradeTooHighException();
        } else
            std::cout << "Form constructor called" << std::endl << std::endl;
        
    }

Form::Form(const Form &other)
    : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
    {
        std::cout << "Form copy constructor called!" << std::endl;
    }

Form    &Form::operator=(const Form &other) {
    if (this != &other) {
        _isSigned = other._isSigned;
    }
    std::cout << "Form operator called!" << std::endl;

    return *this;
}

Form::~Form(){
    std::cout << "Form destructor called!" << std::endl;
}

std::string Form::getName() const {
    return this->_name;
}

bool Form::getIsSigned() const {
    return this->_isSigned;
}

int Form::getGradeToSign() const {
    return this->_gradeToSign;
}

int Form::getGradeToExecute() const {
    return this->_gradeToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > this->_gradeToSign) {
        throw GradeTooLowException();
    }
    this->_isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw() {
    return "grade too high";
}

const char *Form::GradeTooLowException::what() const throw() {
    return "grade too low";
}

std::ostream &operator<<(std::ostream &out, const Form &form) {
    out << "Form " << form.getName() << ", signed: " << (form.getIsSigned() ? "yes" : "no")
        << ", grade to sign: " << form.getGradeToSign() 
        << ", grade to execute: " << form.getGradeToExecute();
    
    return out;
}

