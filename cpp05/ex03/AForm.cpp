/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 18:13:59 by ecoelho-          #+#    #+#             */
/*   Updated: 2025/10/30 22:57:27 by ecoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute, const std::string &target)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _target(target)
{
        if (gradeToSign < 1 || gradeToExecute < 1)
            throw GradeTooHighException();
        if (gradeToSign > 150 || gradeToExecute > 150)
            throw GradeTooLowException();
        
}

AForm::AForm(const AForm &other)
    : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute), _target(other._target)
{
        std::cout << "Form copy constructor called!" << std::endl;
}

AForm    &AForm::operator=(const AForm &other) {
    if (this != &other) {
        _isSigned = other._isSigned;
    }
    std::cout << "Form operator called!" << std::endl;

    return *this;
}

AForm::~AForm(){
    std::cout << "Form destructor called!" << std::endl;
}

std::string AForm::getName() const {
    return this->_name;
}

std::string AForm::getTarget() const {
    return this->_target;
}

bool AForm::getIsSigned() const {
    return this->_isSigned;
}

int AForm::getGradeToSign() const {
    return this->_gradeToSign;
}

int AForm::getGradeToExecute() const {
    return this->_gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > this->_gradeToSign) {
        throw GradeTooLowException();
    }
    this->_isSigned = true;
}

void AForm::execute(Bureaucrat const &executor) const {
    if (!this->_isSigned) {
        throw FormNotSignedException();
    }

    if (executor.getGrade() > this->_gradeToExecute) {
        throw GradeTooLowException();
    }

    this->executeAction();
}


const char *AForm::GradeTooHighException::what() const throw() {
    return "grade too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "grade too low";
}

const char *AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed yet";
}

std::ostream &operator<<(std::ostream &out, const AForm &form) {
    out << "Form " << form.getName() << ", signed: " << (form.getIsSigned() ? "yes" : "no")
        << ", grade to sign: " << form.getGradeToSign() 
        << ", grade to execute: " << form.getGradeToExecute();
    
    return out;
}

