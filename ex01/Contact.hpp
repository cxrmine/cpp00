/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalkawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 16:50:21 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/06/01 16:50:21 by tmalkawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
public:
  Contact();
  ~Contact();

  std::string firstName;
  std::string lastName;
  std::string nickname;
  std::string darkestSecret;
  std::string phoneNumber;
  std::size_t index;
};

#endif
