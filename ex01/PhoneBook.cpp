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
}

void PhoneBook::add(Contact *contact, PhoneBook *phoneBook) {
  if (contact == NULL || phoneBook == NULL)
    return;

  PhoneBook::askUserCredentials(contact);

  if (PhoneBook::isFull()) {
    contact->index = 8;
    phoneBook->contacts[0] = *contact;
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

  std::cout << "Enter index: ";
  std::cin >> input;

  if (!PhoneBook::isNumber(input)) {
    std::cout
        << "Invalid input, please use digits in range of [1 - 8] (8 included)"
        << "\n";
    return;
  }

  ss << input;
  ss >> index;

  if (index > phoneBook->size || index < 1) {
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

std::string PhoneBook::truncateIfLong(std::string cred) {
  if (cred.size() > COLUMN_WIDTH)
    return cred.substr(0, COLUMN_WIDTH - 1).append(".");
  return cred;
}

PhoneBook::PhoneBook() {
  PhoneBook::size = 0;
  PhoneBook::max = 8;
}

PhoneBook::~PhoneBook() { return; }
