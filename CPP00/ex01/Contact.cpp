/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/18 15:03:48 by dritsema      #+#    #+#                 */
/*   Updated: 2023/04/21 12:26:23 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Contact.hpp>
#include <iostream>

void	Contact::print(void)
{
	std::cout << "  First name  : " << first_name << std::endl;
	std::cout << "  Last name   : " << last_name << std::endl;
	std::cout << "   Nickname   : " << nickname << std::endl;
	std::cout << " Phone number : " << phone_number << std::endl;
	std::cout << "Darkest secret: " << darkest_secret << std::endl;
}

void		Contact::setAttribute(e_attribute attr, std::string str)
{
	attributes[static_cast<int>(attr)] = str;
}

std::string	Contact::getAttribute(e_attribute attr)
{
	return (attributes[static_cast<int>(attr)]);
}

void		Contact::setFirstName(std::string str)
{
	first_name = str;
}

std::string	Contact::getFirstName(void)
{
	return (first_name);
}

void		Contact::setLasttName(std::string str)
{
	last_name = str;
}

std::string	Contact::getLasttName(void)
{
	return (last_name);
}

void		Contact::setNickname(std::string str)
{
	nickname = str;
}

std::string	Contact::getNickname(void)
{
	return (nickname);
}

void		Contact::setPhoneNumber(std::string str)
{
	phone_number = str;
}

std::string	Contact::getPhoneNumber(void)
{
	return (phone_number);
}

void		Contact::setDarkestSecret(std::string str)
{
	darkest_secret = str;
}

std::string	Contact::getDarkestSecret(void)
{
	return (darkest_secret);
}
