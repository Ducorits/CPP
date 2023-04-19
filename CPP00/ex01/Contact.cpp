/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/18 15:03:48 by dritsema      #+#    #+#                 */
/*   Updated: 2023/04/19 11:50:54 by dritsema      ########   odam.nl         */
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
