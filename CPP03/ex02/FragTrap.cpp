/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/26 13:23:37 by dritsema      #+#    #+#                 */
/*   Updated: 2023/06/02 13:45:52 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <FragTrap.hpp>
#include <iostream>

FragTrap::FragTrap()
{
	name = "";
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
	std::cout << name << " has specialized into a FragTrap." << std::endl;
}

FragTrap::FragTrap(const std::string& str) : ClapTrap::ClapTrap(str)
{
	name = str;
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
	std::cout << name << " has specialized into a FragTrap." << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap::ClapTrap(other.name)
{
	name = other.name;
	hit_points = other.hit_points;
	energy_points = other.energy_points;
	attack_damage = other.attack_damage;
	std::cout << name << " has specialized into a FragTrap." << std::endl;

}

FragTrap::~FragTrap()
{
	std::cout << name << " has discarded its FragTrap status." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this == &other)
		return (*this);
	name = other.name;
	hit_points = other.hit_points;
	energy_points = other.energy_points;
	attack_damage = other.attack_damage;
	std::cout << name << " was copied. So now there could be multiple " << name << std::endl;
	return (*this);
}

void FragTrap::highFivesGuys(void)
{
	std::cout << name << " is shaking for a high five. SO excited! 'Give it to meeee!'" << std::endl;
}
