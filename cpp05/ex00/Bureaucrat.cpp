/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 21:37:06 by ecoelho-          #+#    #+#             */
/*   Updated: 2025/10/27 21:37:09 by ecoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade): _name(name), _grade(grade) {
    std::cout << "Bureaucrat " << name << " was created with grade: " << grade << std::endl << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other._name), _grade(other._grade) {
    std::cout << "Bureaucrat copy constructor called!" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
    if (this != &other) {
        this->_grade = other._grade;
    }
    std::cout << "Bureaucrat operator called!" << std::endl;
    return *this;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat " << this->_name << " was destructor" << std::endl;
}

std::string Bureaucrat::getName() const {
    return this->_name;
}

int Bureaucrat::getGrade() const {
    return this->_grade;
}

void Bureaucrat::increment() {
    try {
        if (this->_grade <= 1)
            throw Bureaucrat::GradeTooHighException();
        this->_grade--;   
    } catch (std::exception &e) {
        std::cout << "Increment failed... " << e.what() << std::endl;
    }
}

void Bureaucrat::decrement() {
    try {
        if (this->_grade >= 150)
            throw Bureaucrat::GradeTooLowException();
        this->_grade++;
    } catch (std::exception &e) {
        std::cout << "Decrement failed... " << e.what() << std::endl;
    }
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Bureaucrat grade is out of the range, the max is: 1";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Bureaucrat grade is out of the range, the min is: 150";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b) {
    os << b.getName() << ", Bureaucrat grade: " << b.getGrade() << ".";
    return os;
}
