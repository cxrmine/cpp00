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

#include <iostream>
#include "PhoneBook.hpp"

int main () {
	std::string test;
	PhoneBook phoneBook;

	while (true) {
		std::cout << "enter something: ";
		std::cin >> test;
		if (test == "q")
			break ;
	}
	std::cout << phoneBook.max << std::endl;
	return 0;
}
