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

  if (phoneBook->size == 0)
    return;

  std::cout << std::setw(s_idx.size()) << s_idx << "|";
  std::cout << std::setw(s_fname.size()) << s_fname << "|";
  std::cout << std::setw(s_lname.size()) << s_lname << "|";
  std::cout << std::setw(s_nick.size()) << s_nick << "\n";
  std::cout << std::setw(s_idx.size()) << phoneBook->contacts[index].index
            << "|";
  std::cout << std::setw(s_fname.size()) << phoneBook->contacts[index].firstName
            << "|";
  std::cout << std::setw(s_lname.size()) << phoneBook->contacts[index].lastName
            << "|";
  std::cout << std::setw(s_nick.size()) << phoneBook->contacts[index].nickname
            << "\n";
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
