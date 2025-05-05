/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:12:42 by ecoelho-          #+#    #+#             */
/*   Updated: 2025/05/02 21:29:30 by ecoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int main(void) {
  std::string read;
  Phonebook book;
  std::cout << "PHONEBOOK: ";

  while (getline(std::cin, read)) {

    if (read.compare("EXIT") == 0)
      break;
    else if (read.compare("ADD") == 0) {
      book.add();
    } else if (read.compare("SEARCH") == 0) {
      book.search();
    } else {
      std::cout << "Command not found" << std::endl;
      std::cout << "PHONEBOOK: ";
    }
  }

  return (0);
}
