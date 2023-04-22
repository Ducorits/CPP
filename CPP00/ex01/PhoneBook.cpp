/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   phonebook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/17 19:40:40 by dritsema      #+#    #+#                 */
/*   Updated: 2023/04/22 18:39:59 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <PhoneBook.hpp>
#include <Contact.hpp>
#include <iostream>
#include <iomanip>

void	PhoneBook::add(void)
{
	Contact		c;
	std::string	str;

	std::cout << "Adding contact please enter the following info." << std::endl;
	std::cout << "  First name  : ";
	std::getline(std::cin, str);
	c.setAttribute(FIRST_NAME, str);
	std::cout << "  Last name   : ";
	std::getline(std::cin, str);
	c.setAttribute(LAST_NAME, str);
	std::cout << "   Nickname   : ";
	std::getline(std::cin, str);
	c.setAttribute(NICKNAME, str);
	std::cout << " Phone number : ";
	std::getline(std::cin, str);
	c.setAttribute(PHONE_NUMBER, str);
	std::cout << "Darkest secret: ";
	std::getline(std::cin, str);
	c.setAttribute(DARKEST_SECRET, str);

	if (index < 8)
	{
		contacts[index] = c;
		index++;
	}
	else
	{
		for (int i = 7; i > 0; i--)
			contacts[i] = contacts[i - 1];
		contacts[0] = c;
	}
	std::cout << "Added " << c.getAttribute(FIRST_NAME) << " to contacts" << std::endl;
}

void	PhoneBook::search(void)
{
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	str;
	int			i;

	for (int i = 0; i < 8; i++)
	{
		first_name = contacts[i].getAttribute(FIRST_NAME).substr(0, 10);
		last_name = contacts[i].getAttribute(LAST_NAME).substr(0, 10);
		nickname = contacts[i].getAttribute(NICKNAME).substr(0, 10);
		if (first_name.length() == 10)
			first_name[9] = '.';
		if (last_name.length() == 10)
			last_name[9] = '.';
		if (nickname.length() == 10)
			nickname[9] = '.';
		std::cout << "|" << std::setw(10) << std::right << i << "|";
		std::cout << std::setw(10) << std::right << first_name << "|";
		std::cout << std::setw(10) << std::right << last_name << "|";
		std::cout << std::setw(10) << std::right << nickname << "|" << std::endl;
	}
	std::cout << "Entry to display: ";
	std::getline(std::cin, str);
	i = std::stoi(str);
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
