/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/18 15:03:48 by dritsema      #+#    #+#                 */
/*   Updated: 2023/04/22 15:52:45 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Contact.hpp>
#include <iostream>

void	Contact::print(void)
{
	std::cout << "  First name  : " << attributes[FIRST_NAME] << std::endl;
	std::cout << "  Last name   : " << attributes[LAST_NAME] << std::endl;
	std::cout << "   Nickname   : " << attributes[NICKNAME] << std::endl;
	std::cout << " Phone number : " << attributes[PHONE_NUMBER] << std::endl;
	std::cout << "Darkest secret: " << attributes[DARKEST_SECRET] << std::endl;
}

void		Contact::setAttribute(e_attribute attr, std::string str)
{
	attributes[static_cast<int>(attr)] = str;
}

std::string	Contact::getAttribute(e_attribute attr)
{
	return (attributes[static_cast<int>(attr)]);
}
