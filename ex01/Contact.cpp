/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalkawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:00:28 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/06/02 16:00:28 by tmalkawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {
  Contact::firstName = "";
  Contact::lastName = "";
  Contact::darkestSecret = "";
  Contact::phoneNumber = "";
  Contact::index = 0;
}

Contact::~Contact() { return; }
