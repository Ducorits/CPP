/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/23 21:25:37 by dritsema      #+#    #+#                 */
/*   Updated: 2023/04/24 15:50:48 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main()
{
	std::string	str = "HI THIS IS BRAIN";
	std::string *strPTR = &str;
	std::string	&strREF = str;

	std::cout << &str << std::endl;
	std::cout << &strPTR << std::endl;
	std::cout << &strREF << std::endl;

	std::cout << str << std::endl;
	std::cout << strPTR << std::endl;
	std::cout << strREF << std::endl;
}
