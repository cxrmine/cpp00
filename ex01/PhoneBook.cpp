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
#include <sstream>
#include <string>

bool PhoneBook::isFull() {
  if (PhoneBook::size == PhoneBook::max)
    return true;
  return false;
}

void PhoneBook::askUserCredentials(Contact *contact) {
  if (contact == NULL)
    return;

  std::string input;

  std::cout << "\n" << "first name" << "\n";
  std::cout << "-> ";
  std::cin >> input;
  contact->firstName = input;

  std::cout << "\n" << "last name" << "\n";
  std::cout << "-> ";
  std::cin >> input;
  contact->lastName = input;

  std::cout << "\n" << "phone number" << "\n";
  std::cout << "-> ";
  std::cin >> input;
  contact->phoneNumber = input;

  std::cout << "\n" << "nickname" << "\n";
  std::cout << "-> ";
  std::cin >> input;
  contact->nickname = input;

  std::cout << "\n" << "darkest secret" << "\n";
  std::cout << "-> ";
  std::cin >> input;
  contact->darkestSecret = input;

  std::cout << "\n";
}

void PhoneBook::add(Contact *contact, PhoneBook *phoneBook) {
  if (contact == NULL || phoneBook == NULL)
    return;

  PhoneBook::askUserCredentials(contact);

  if (PhoneBook::isFull()) {
    if (phoneBook->oldest > phoneBook->max + 1)
      phoneBook->oldest = 0;
    contact->index = phoneBook->oldest + 1;
    phoneBook->contacts[phoneBook->oldest] = *contact;
    phoneBook->oldest++;
    return;
  }
  contact->index = phoneBook->size + 1;
  phoneBook->contacts[phoneBook->size] = *contact;
  phoneBook->size++;
}

void PhoneBook::print(PhoneBook *phoneBook, std::size_t index) {
  std::string s_idx = "index";
  std::string s_fname = "first name";
  std::string s_lname = "last name";
  std::string s_nick = "nickname";
  Contact contact = phoneBook->contacts[index];

  if (phoneBook->size == 0)
    return;

  std::cout << "\n";
  std::cout << std::setw(COLUMN_WIDTH) << s_idx << "|";
  std::cout << std::setw(COLUMN_WIDTH) << s_fname << "|";
  std::cout << std::setw(COLUMN_WIDTH) << s_lname << "|";
  std::cout << std::setw(COLUMN_WIDTH) << s_nick << "\n";
  std::cout << std::setw(COLUMN_WIDTH) << contact.index << "|";
  std::cout << std::setw(COLUMN_WIDTH)
            << PhoneBook::truncateIfLong(contact.firstName) << "|";
  std::cout << std::setw(COLUMN_WIDTH)
            << PhoneBook::truncateIfLong(contact.lastName) << "|";
  std::cout << std::setw(COLUMN_WIDTH)
            << PhoneBook::truncateIfLong(contact.nickname) << "\n";
  std::cout << "\n";
  return;
}

bool PhoneBook::isNumber(std::string input) {
  for (std::string::iterator it = input.begin(), end = input.end(); it != end;
       ++it) {
    char c = *it;

    if (c == '-')
      continue;
    if (c < 48 || c > 57)
      return false;
  }
  return true;
}

void PhoneBook::search(PhoneBook *phoneBook) {
  std::stringstream ss;
  std::size_t index;
  std::string input;

  std::cout << "\n" << "Enter index" << "\n";
  std::cout << "-> ";
  std::cin >> input;

  if (!PhoneBook::isNumber(input)) {
    std::cout
        << "Invalid input, please use digits in range of [1 - 8] (8 included)"
        << "\n";
    return;
  }

  ss << input;
  ss >> index;

  if (phoneBook->size == 0) {
    std::cout << "you haven't added any contacts yet, please do with ADD"
              << "\n";
    return;
  }

  if (index > phoneBook->size || index < 1) {
    std::cout << "this contact doesn't exists..." << "\n";
    return;
  }

  index = index - 1;
  PhoneBook::print(phoneBook, index);
  return;
}

std::string PhoneBook::truncateIfLong(std::string cred) {
  if (cred.size() > COLUMN_WIDTH)
    return cred.substr(0, COLUMN_WIDTH - 1).append(".");
  return cred;
}

PhoneBook::PhoneBook() {
  PhoneBook::size = 0;
  PhoneBook::max = 8;
  PhoneBook::oldest = 0;
}

PhoneBook::~PhoneBook() { return; }
