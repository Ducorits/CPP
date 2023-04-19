/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/18 15:05:07 by dritsema      #+#    #+#                 */
/*   Updated: 2023/04/19 16:06:40 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <PhoneBook.hpp>
#include <Contact.hpp>
#include <iostream>
#include <string>

int	main(void)
{
	std::string	input;
	PhoneBook	book;

	std::cout << "PhoneBook. Type one of the following commands to start: [ADD, SEARCH, EXIT]" << std::endl;
	std::getline(std::cin, input);

	while (1)
	{
		if (input == "ADD")
		{
			book.add();
		}
		else if (input == "SEARCH")
		{
			std::cout << "test " << input << std::endl;
			book.search();
		}
		else if (input == "EXIT")
		{
			std::cout << "test " << input << std::endl;
			book.exit();
			break;
		}
		std::getline(std::cin, input);
	}
	return (0);
}
