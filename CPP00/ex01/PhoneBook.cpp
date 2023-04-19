/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   phonebook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/17 19:40:40 by dritsema      #+#    #+#                 */
/*   Updated: 2023/04/19 16:04:36 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <PhoneBook.hpp>
#include <Contact.hpp>
#include <iostream>

void	PhoneBook::add(void)
{
	Contact	c;

	std::cout << "Adding contact please enter the following info." << std::endl;
	std::cout << "  First name  : ";
	std::getline(std::cin, c.first_name);
	std::cout << "  Last name   : ";
	std::getline(std::cin, c.last_name);
	std::cout << "   Nickname   : ";
	std::getline(std::cin, c.nickname);
	std::cout << " Phone number : ";
	std::getline(std::cin, c.phone_number);
	std::cout << "Darkest secret: ";
	std::getline(std::cin, c.darkest_secret);

	contacts[index] = c;
	if (index < 8)
		index++;
	else
	{
		for (int i = 7; i > 0; i--)
			contacts[i] = contacts[i - 1];
		contacts[0] = c;
	}
	std::cout << "Added " << c.first_name << " to contacts" << std::endl;
}

void	PhoneBook::search(void)
{

}

void	PhoneBook::exit(void)
{

}

// void	PhoneBook::print_contact(void)
// {

// }

PhoneBook::PhoneBook(void)
{
	index = 0;
}
