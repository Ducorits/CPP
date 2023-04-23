/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/23 21:10:51 by dritsema      #+#    #+#                 */
/*   Updated: 2023/04/23 22:18:57 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>
#include <iostream>

Zombie::Zombie(std::string n)
{
	this->name = n;
}

Zombie::~Zombie()
{
	std::cout << name << " has finally rotted away." << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::set_name( std::string n )
{
	name = n;
}
