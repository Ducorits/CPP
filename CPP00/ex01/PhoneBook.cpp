/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   phonebook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/17 19:40:40 by dritsema      #+#    #+#                 */
/*   Updated: 2023/04/21 12:27:50 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <PhoneBook.hpp>
#include <Contact.hpp>
#include <iostream>

void	PhoneBook::add(void)
{
	Contact		c;
	std::string	str;

	std::cout << "Adding contact please enter the following info." << std::endl;
	std::cout << "  First name  : ";
	std::getline(std::cin, str);
	c.setAttribute(first_name, str);
	std::cout << "  Last name   : ";
	std::getline(std::cin, str);
	c.setAttribute(last_name, str);
	std::cout << "   Nickname   : ";
	std::getline(std::cin, str);
	c.setAttribute(nickname, str);
	std::cout << " Phone number : ";
	std::getline(std::cin, str);
	c.setAttribute(phone_number, str);
	std::cout << "Darkest secret: ";
	std::getline(std::cin, str);
	c.setAttribute(darkest_secret, str);

	contacts[index] = c;
	if (index < 8)
		index++;
	else
	{
		for (int i = 7; i > 0; i--)
			contacts[i] = contacts[i - 1];
		contacts[0] = c;
	}
	std::cout << "Added " << c.getAttribute(first_name) << " to contacts" << std::endl;
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
