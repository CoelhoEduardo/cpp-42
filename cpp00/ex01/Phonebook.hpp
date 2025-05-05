/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:12:53 by ecoelho-          #+#    #+#             */
/*   Updated: 2025/05/02 21:20:27 by ecoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
#define PHONEBOOK_CLASS_H

#include "Contact.hpp"

class Phonebook {
public:
  Phonebook(void);
  ~Phonebook(void);
  void add();
  int index;
  void search();

private:
  void display_contacts(void);
  Contact contact[8];
};

#endif // !PHONEBOOK_CLASS_H
