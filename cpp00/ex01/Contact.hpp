/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:12:39 by ecoelho-          #+#    #+#             */
/*   Updated: 2025/05/02 21:53:11 by ecoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
#define CONTACT_CLASS_H

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

class Contact {
public:
  Contact(void);
  ~Contact(void);
  std::string prompt_field(const std::string &message);
  void set_contact(int id);
  std::string get_id(void);
  std::string get_firstname(void);
  std::string get_lastname(void);
  std::string get_nickname(void);
  std::string get_phone(void);
  std::string get_darkest_secret(void);

private:
  std::string _id;
  std::string _firstname;
  std::string _lastname;
  std::string _nickname;
  std::string _phone;
  std::string _darkest_secret;
};

#endif
