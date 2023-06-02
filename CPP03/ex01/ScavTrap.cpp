/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/19 18:07:35 by dritsema      #+#    #+#                 */
/*   Updated: 2023/06/02 13:44:20 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ScavTrap.hpp>
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap()
{
	name = "";
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
	std::cout << "'" << name << "' has specialized into a ScavTrap." << std::endl;
}

ScavTrap::ScavTrap(const std::string& str) : ClapTrap(str)
{
	name = str;
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
	std::cout << name << " has specialized into a ScavTrap." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other.name)
{
	*this = other;
	std::cout << name << " has specialized into a ScavTrap." << std::endl;

}

ScavTrap::~ScavTrap()
{
	std::cout << name << " has discarded its ScavTrap status." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << name << " was copied. So now there could be multiple " << name << std::endl;
	if (this == &other)
		return (*this);
	name = other.name;
	hit_points = other.hit_points;
	energy_points = other.energy_points;
	attack_damage = other.attack_damage;
	return (*this);
}

void ScavTrap::attack(const std::string& target)
{
	if (energy_points > 0 && hit_points > 0)
	{
		energy_points -= 1;
		std::cout << "ScavTrap " << name << ", attacks " << target << ", causing " << attack_damage << " points of damage! 'Mwuhahaha Fall before the might of the ScavTrap! Hahahaha!'" << std::endl;
	}
	else
		std::cout << "ScavTrap " << name << ", tried to attack but failed due to a lack of hit or energy points. 'Oh darn, it seems this ScavTrap lost it's might!'" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << name << " is now 'OP', for he has entered 'Gate Keeper' mode!" << std::endl;
}
