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

int main() {
  std::string test;
  PhoneBook phoneBook;
  Contact contact;

  while (true) {
    std::cout << "enter something: ";
    std::cin >> test;
    if (test == "ADD") {
      phoneBook.add(&contact, &phoneBook);
    } else if (test == "SEARCH") {
      phoneBook.search(&contact, &phoneBook);
    } else if (test == "EXIT") {
    	break ;
    }
  }
  phoneBook.print(&phoneBook);
  return 0;
}
