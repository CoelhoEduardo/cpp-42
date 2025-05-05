/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:12:50 by ecoelho-          #+#    #+#             */
/*   Updated: 2025/05/02 21:52:02 by ecoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook(void) {
  std::cout << "**************************" << std::endl;
  std::cout << "* Welcome to Phonebook📒 *" << std::endl;
  std::cout << "**************************" << std::endl;
  std::cout << "All commands available (write in capslock)" << std::endl;
  std::cout << "<ADD> <SEARCH> <EXIT>" << std::endl;
  this->index = 0;
  return;
}

Phonebook::~Phonebook(void) { return; }

void Phonebook::add(void) {
  int index;

  index = this->index;
  if (index > 7) {
    index = this->index % 8;
  }
  this->contact[index].set_contact(index);
  this->index++;
  std::cout << std::endl << "Contact added !" << std::endl;
  std::cout << std::endl << "PHONEBOOK: ";

  return;
}

void Phonebook::search(void) {
  std::string line;
  int i;

  if (this->index == 0) {
    std::cout << "No contacts found!\n Add a contact :)" << std::endl;
    std::cout << "PHONEBOOK: ";

    return;
  }
  this->display_contacts();
  std::cout << "Search: ";
  std::getline(std::cin, line);
  if (std::isdigit(line[0]) && line.length() == 1) {
    i = std::atoi(line.c_str());
    if (i >= this->index || i > 7) {
      std::cout << "Error! ID is out of range" << std::endl;
      std::cout << "PHONEBOOK: ";
    } else {
      std::cout << "First Name: " << this->contact[i].get_firstname()
                << std::endl;
      std::cout << "Last Name: " << this->contact[i].get_lastname()
                << std::endl;
      std::cout << "Nickname: " << this->contact[i].get_nickname() << std::endl;
      std::cout << "Phone Number: " << this->contact[i].get_phone()
                << std::endl;
      std::cout << "Darkest Secret: " << this->contact[i].get_darkest_secret()
                << std::endl
                << std::endl;
      std::cout << "PHONEBOOK: ";
    }
  } else {
    std::cout << "Error! ID is not valid" << std::endl;
    std::cout << "PHONEBOOK: ";
  }

  return;
}

static void print_contacts(std::string str) {
  std::cout << "|";
  if (str.length() > 10) {
    std::cout << std::setw(10) << str.substr(0, 9) + ".";
  } else {
    std::cout << std::setw(10) << std::right << str;
  }
}

void Phonebook::display_contacts(void) {
  std::cout << "|" << std::setw(10) << "Index" << "|" << std::setw(10)
            << "First Name" << "|" << std::setw(10) << "Last Name" << "|"
            << std::setw(10) << "Nickname" << "|" << std::endl;

  for (int j = 0; j < this->index && j < 8; j++) {
    print_contacts(this->contact[j].get_id());
    print_contacts(this->contact[j].get_firstname());
    print_contacts(this->contact[j].get_lastname());
    print_contacts(this->contact[j].get_nickname());
    std::cout << "|" << std::endl;
  }
}
