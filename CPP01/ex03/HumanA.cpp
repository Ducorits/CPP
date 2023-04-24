/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanA.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 15:54:02 by dritsema      #+#    #+#                 */
/*   Updated: 2023/04/24 17:04:42 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <HumanA.hpp>
#include <iostream>

HumanA::HumanA(std::string n, Weapon &w)
{
	this->name = n;
	this->weapon = &w;
}

HumanA::~HumanA()
{

}

void	HumanA::attack(void)
{
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}
