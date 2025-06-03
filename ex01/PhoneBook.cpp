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
	std::cout << "darkest secret: ";
	std::cin >> input;
	contact->darkestSecret = input;
	phoneBook->contacts[phoneBook->size] = *contact;
	phoneBook->size++;
}
}

PhoneBook::PhoneBook() {
	PhoneBook::size = 0;
	PhoneBook::max = 8;
}

PhoneBook::~PhoneBook() {
	return ;
}
