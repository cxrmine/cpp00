/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalkawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 16:21:32 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/06/01 16:21:32 by tmalkawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <istream>

int main() {
  std::string test;
  PhoneBook phoneBook;
  Contact contact;

  std::cout << "Enter one of the options listed: [ADD - SEARCH - EXIT] (all "
               "options are case sensitive)"
            << "\n";
  std::cout << "ADD: Add a contact to the list of contact" << "\n";
  std::cout
      << "SEARCH: Search a contact by their index [index range from 1 to 8]"
      << "\n";
  std::cout << "EXIT: You are tired of how beautiful the code is so you "
               "decided you want to exit"
            << "\n";
  std::cout << "-> ";
  while (std::cin >> test) {
    if (test == "ADD") {
      phoneBook.add(&contact, &phoneBook);
    } else if (test == "SEARCH") {
      phoneBook.search(&phoneBook);
    } else if (test == "EXIT") {
      break;
    }

    std::cout << "Enter one of the options listed: [ADD - SEARCH - EXIT] (all "
                 "options are case sensitive)"
              << "\n";
    std::cout << "ADD: Add a contact to the list of contact" << "\n";
    std::cout
        << "SEARCH: Search a contact by their index [index range from 1 to 8]"
        << "\n";
    std::cout << "EXIT: You are tired of how beautiful the code is so you "
                 "decided you want to exit"
              << "\n";
    std::cout << "-> ";
    std::cin.clear();
    std::cin.ignore(256, '\n');
  }
  return 0;
}
