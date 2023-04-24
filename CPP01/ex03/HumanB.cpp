/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 15:54:03 by dritsema      #+#    #+#                 */
/*   Updated: 2023/04/24 17:04:45 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <HumanB.hpp>
#include <iostream>

HumanB::HumanB(std::string n)
{
	this->name = n;
}

HumanB::~HumanB()
{

}

void	HumanB::attack(void)
{
	std::cout << this->name << " attacks with their " << (*this->weapon).getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &w)
{
	this->weapon = &w;
}
