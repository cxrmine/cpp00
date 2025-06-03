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
#include <iostream>
#include <sstream>

bool PhoneBook::isFull() {
	if (PhoneBook::size == PhoneBook::max)
		return true;
	return false;
}

void PhoneBook::add(Contact *contact, PhoneBook *phoneBook) {
	std::string input;

	if (PhoneBook::isFull())
		return ;
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
	contact->index = phoneBook->size + 1;
	phoneBook->contacts[phoneBook->size] = *contact;
	phoneBook->size++;
}

void PhoneBook::print(PhoneBook *phoneBook)
{
	 if (phoneBook->size == 0)	
		 return ;
	 for (std::size_t i = 0; i < phoneBook->size; i++) {
	 	std::cout << phoneBook->contacts[i].index << '\n';
	 	std::cout << phoneBook->contacts[i].firstName << '\n';
	 	std::cout << phoneBook->contacts[i].lastName << '\n';
	 	std::cout << phoneBook->contacts[i].phoneNumber << '\n';
	 	std::cout << phoneBook->contacts[i].darkestSecret << '\n';
	 }
	 return ;
}

void PhoneBook::search(Contact *contact, PhoneBook *phoneBook)
{
	std::stringstream ss;
	std::size_t index;
	std::string input;

	(void) contact;
	std::cout << "Enter index: ";
	std::cin >> input;
	ss << input;
	ss >> index;
	if (phoneBook->size == 0)
		return ;
	index = index - 1;
	std::cout << phoneBook->contacts[index].index << "\n";
	std::cout << phoneBook->contacts[index].firstName << "\n";
	std::cout << phoneBook->contacts[index].lastName << "\n";
	std::cout << phoneBook->contacts[index].darkestSecret << "\n";
	std::cout << phoneBook->contacts[index].phoneNumber << "\n";
	return ;
}

PhoneBook::PhoneBook() {
	PhoneBook::size = 0;
	PhoneBook::max = 8;
}

PhoneBook::~PhoneBook() {
	return ;
}
