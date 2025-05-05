/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:12:33 by ecoelho-          #+#    #+#             */
/*   Updated: 2025/05/02 21:53:15 by ecoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {}

Contact::~Contact(void) {}

std::string Contact::prompt_field(const std::string &message) {
  std::string input;
  std::cout << message;
  std::getline(std::cin, input);
  while (input.empty()) {
    std::cout << "Failed can't be empty!\nPlease fill this input: ";
    std::getline(std::cin, input);
  }

  return input;
}

void Contact::set_contact(int id) {
  std::ostringstream id_str;
  id_str << id;
  this->_id = id_str.str();

  this->_firstname = prompt_field("Enter First Name 🤖: ");
  this->_lastname = prompt_field("Enter Last Name 🤖: ");
  this->_nickname = prompt_field("Enter Nickname 🤖: ");
  this->_phone = prompt_field("Enter Phone Number 📱: ");
  this->_darkest_secret = prompt_field("Enter Darkest Secret 👹: ");
}

std::string Contact::get_id(void) { return (this->_id); }

std::string Contact::get_firstname(void) { return (this->_firstname); }

std::string Contact::get_lastname(void) { return (this->_lastname); }

std::string Contact::get_nickname(void) { return (this->_nickname); }

std::string Contact::get_phone(void) { return (this->_phone); }

std::string Contact::get_darkest_secret(void) {
  return (this->_darkest_secret);
}

// void Contact::set_contact(int id) {
//   std::stringstream id_str;
//   id_str << id;
//   this->_id = id_str.str();
//   std::cout << "Enter First Name: ";
//   std::getline(std::cin, this->_firstname);
//   while (this->_firstname.length() == 0) {
//     std::cout << "Field Can't Be Empty!\nPlease fill this input: ";
//     std::getline(std::cin, this->_firstname);
//   }
//   std::cout << "Enter Last Name: ";
//   std::getline(std::cin, this->_lastname);
//   while (this->_lastname.length() == 0) {
//     std::cout << "Field Cant't Be Empty!\nPlease fill this input: ";
//     std::getline(std::cin, this->_lastname);
//   }
//   std::cout << "Enter Nickname: ";
//   std::getline(std::cin, this->_nickname);
//   while (this->_nickname.length() == 0) {
//     std::cout << "Field Cant't Be Empty!\nPlease fill this input: ";
//     std::getline(std::cin, this->_nickname);
//   }
//   std::cout << "Enter Phone Number: ";
//   std::getline(std::cin, this->_phone);
//   while (this->_phone.length() == 0) {
//     std::cout << "Field Cant't Be Empty!\nPlease fill this input: ";
//     std::getline(std::cin, this->_phone);
//   }
//   std::cout << "Enter Darkest Secret: ";
//   std::getline(std::cin, this->_darkest_secret);
//   while (this->_darkest_secret.length() == 0) {
//     std::cout << "Field Cant't Be Empty!\nPlease fill this input: ";
//     std::getline(std::cin, this->_darkest_secret);
//   }
// }
