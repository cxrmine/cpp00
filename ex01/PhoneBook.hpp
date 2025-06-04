/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalkawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 16:48:47 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/06/01 16:48:47 by tmalkawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

#define COLUMN_WIDTH 10

class PhoneBook {
public:
  PhoneBook();
  ~PhoneBook();

  std::size_t size;
  std::size_t max;
  std::size_t oldest;
  Contact contacts[8];

  void add(Contact *contact, PhoneBook *phoneBook);
  void search(PhoneBook *phoneBook);

private:
  bool isFull(void);
  bool isNumber(std::string input);
  void print(PhoneBook *phoneBook, std::size_t index);
  void askUserCredentials(Contact *contact);
  std::string truncateIfLong(std::string cred);
};

#endif
