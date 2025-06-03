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

class PhoneBook {
public:
  PhoneBook();
  ~PhoneBook();

  std::size_t size;
  std::size_t max;
  Contact contacts[8];

  bool isFull(void);
  void print(PhoneBook *phoneBook);
  void add(Contact *contact, PhoneBook *phoneBook);
  void search(std::string input, Contact *contact, PhoneBook *phoneBook);
};

#endif
