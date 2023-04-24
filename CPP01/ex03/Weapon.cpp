/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 15:53:56 by dritsema      #+#    #+#                 */
/*   Updated: 2023/04/24 17:03:50 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Weapon.hpp>

Weapon::Weapon() {}

Weapon::Weapon(std::string str)
{
	this->type = str;
}

Weapon::~Weapon()
{

}

const std::string	&Weapon::getType(void)
{
	return (this->type);
}

void		Weapon::setType(std::string str)
{
	this->type = str;
}
