/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 12:02:54 by ecoelho-          #+#    #+#             */
/*   Updated: 2025/11/10 12:20:30 by ecoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
    std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(const Intern &other) {
    (void)other;
    std::cout << "Intern copy constructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &other) {
    (void)other;
    std::cout << "Intern assignment operator called" << std::endl;
    return *this;
}

Intern::~Intern() {
    std::cout << "Intern destructor called" << std::endl;
}

const char *Intern::UnknownFormException::what() const throw() {
    return "Unknown form name";
}

static AForm *createShrubberyForm(const std::string &target) {
    return new ShrubberyCreationForm(target);
}

static AForm *createRobotomyRequestForm(const std::string &target) {
    return new RobotomyRequestForm(target);
}

static AForm *createPresidentialPardonForm(const std::string &target) {
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) {
    std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm *(*formCreators[3])(const std::string &) = {
        &createShrubberyForm,
        &createRobotomyRequestForm,
        &createPresidentialPardonForm
    };

    for (int i = 0; i < 3; i++) {
        if (formName == formNames[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return formCreators[i](target);
        }
    }

    throw UnknownFormException();
}