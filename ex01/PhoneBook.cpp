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

bool PhoneBook::isFull() {
	if (PhoneBook::size == PhoneBook::max)
		return true;
	return false;
}

void PhoneBook::add(Contact contact) {
	if (PhoneBook::isFull())
		return ;
	PhoneBook::contacts[PhoneBook::size] = contact;
	PhoneBook::size++;
}

PhoneBook::PhoneBook() {
	PhoneBook::size = 0;
	PhoneBook::max = 8;
}

PhoneBook::~PhoneBook() {
	return ;
}
