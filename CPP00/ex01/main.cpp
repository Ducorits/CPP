/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/18 15:05:07 by dritsema      #+#    #+#                 */
/*   Updated: 2023/04/23 20:12:00 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <PhoneBook.hpp>
#include <Contact.hpp>
#include <iostream>
#include <string>


void check_leaks()
{
	system("leaks friendtome");
}

int	main(void)
{
	std::string	input;
	PhoneBook	book;

	std::cout << "MyFriendsTM. Type one of the following commands to use: ADD, SEARCH or EXIT." << std::endl;
	while (1)
	{
		std::cout << "MyFriendsTM: ";
		std::getline(std::cin, input);

		if (input == "ADD")
			book.add();
		else if (input == "SEARCH")
			book.search();
		else if (input == "EXIT")
			break;
	}
	atexit(check_leaks);
	return (0);
}
