/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   phonebook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/17 19:40:40 by dritsema      #+#    #+#                 */
/*   Updated: 2023/04/18 20:44:29 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <PhoneBook.hpp>
#include <Contact.hpp>
#include <iostream>

void PhoneBook::add(void)
{
	Contact	c;

	// std::cout << "Adding contact please enter the following info." << std::endl;
	std::cout << "First name: ";
	std::getline(std::cin, c.first_name);
	// std::cout << std::endl;
	std::cout << "Last name: ";
	std::getline(std::cin, c.last_name);
	std::cout << "Nickname: ";
	std::getline(std::cin, c.nickname);
	std::cout << "Phone number: ";
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
}

void PhoneBook::search(void)
{

}

void PhoneBook::exit(void)
{

}

PhoneBook::PhoneBook(void)
{
	index = 0;
}
