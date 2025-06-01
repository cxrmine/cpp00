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
	  for (std::size_t j = 0; argv[i][j]; j++) {
    		if (argv[i][j] >= 97 && argv[i][j] <= 122)
      			argv[i][j] -= 32;
	  }
  	std::cout << argv[i];
  }

  std::cout << std::endl;
  return 0;
}
