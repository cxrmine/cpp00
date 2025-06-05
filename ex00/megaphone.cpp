/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalkawi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:52:36 by tmalkawi          #+#    #+#             */
/*   Updated: 2025/06/01 13:52:36 by tmalkawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ostream>

int main(int argc, char **argv) {
  if (argc == 1) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return 0;
  }

  for (std::size_t i = 1; argv[i]; i++) {
    std::string s = argv[i];
    for (std::string::iterator it = s.begin(), end = s.end(); it != end; ++it) {
      char c = *it;
      if (c >= 97 && c <= 122)
        c -= 32;
      std::cout << c;
    }
  }

  std::cout << std::endl;
  return 0;
}
