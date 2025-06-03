/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalkawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 17:00:14 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/06/01 17:00:14 by tmalkawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iomanip>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>

bool PhoneBook::isFull() {
  if (PhoneBook::size == PhoneBook::max)
    return true;
  return false;
}

void PhoneBook::add(Contact *contact, PhoneBook *phoneBook) {
  std::string input;

  std::cout << "first name: ";
  std::cin >> input;
  contact->firstName = input;
  std::cout << "last name: ";
  std::cin >> input;
  contact->lastName = input;
  std::cout << "phone number: ";
  std::cin >> input;
  contact->phoneNumber = input;
  std::cout << "nickname: ";
  std::cin >> input;
  contact->nickname = input;
  std::cout << "darkest secret: ";
  std::cin >> input;
  contact->darkestSecret = input;
  if (PhoneBook::isFull()) {
    contact->index = 8;
    phoneBook->contacts[7] = *contact;
    return;
  }
  contact->index = phoneBook->size + 1;
  phoneBook->contacts[phoneBook->size] = *contact;
  phoneBook->size++;
}

void PhoneBook::print(PhoneBook *phoneBook, std::size_t index) {
  std::string string_index = "index";
  std::string string_fname = "first name";
  std::string string_lname = "last name";
  std::string string_nickname = "nickname";
  if (phoneBook->size == 0)
    return;
  std::cout << std::setfill(' ') << std::setw(string_index.size())
            << string_index << "|";
  std::cout << std::setfill(' ') << std::setw(string_fname.size())
            << string_fname << "|";
  std::cout << std::setfill(' ') << std::setw(string_lname.size())
            << string_lname << "|";
  std::cout << std::setfill(' ') << std::setw(string_nickname.size())
            << string_nickname << "\n";
  std::cout << std::setfill(' ') << std::setw(string_index.size())
            << phoneBook->contacts[index].index << "|";
  std::cout << std::setfill(' ') << std::setw(string_fname.size())
            << phoneBook->contacts[index].firstName << "|";
  std::cout << std::setfill(' ') << std::setw(string_lname.size())
            << phoneBook->contacts[index].lastName << "|";
  std::cout << std::setfill(' ') << std::setw(string_nickname.size())
            << phoneBook->contacts[index].nickname << "\n";
  return;
}

void PhoneBook::search(PhoneBook *phoneBook) {
  std::stringstream ss;
  std::size_t index;
  std::string input;

  std::cout << "Enter index: ";
  std::cin >> input;
  ss << input;
  ss >> index;

  if (index > phoneBook->size) {
    std::cout << "this contact doesn't exists..." << "\n";
    return;
  }

  if (phoneBook->size == 0) {
    std::cout << "you haven't added any contacts yet, please do with ADD"
              << "\n";
    return;
  }

  index = index - 1;
  PhoneBook::print(phoneBook, index);
  return;
}

PhoneBook::PhoneBook() {
  PhoneBook::size = 0;
  PhoneBook::max = 8;
}

PhoneBook::~PhoneBook() { return; }
