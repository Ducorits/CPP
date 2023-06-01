/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 18:19:59 by dritsema      #+#    #+#                 */
/*   Updated: 2023/06/01 19:58:44 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ClapTrap.hpp>
#include <iostream>

ClapTrap::ClapTrap()
{
	name = "";
	hit_points = 10;
	energy_points = 10;
	attack_damage = 0;
	std::cout << "ClapTrap '" << name << "' was brought into existence." << std::endl;
}

ClapTrap::ClapTrap(const std::string& str)
{
	name = str;
	hit_points = 10;
	energy_points = 10;
	attack_damage = 0;
	std::cout << "ClapTrap " << name << " was brought into existence." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	name = other.name;
	hit_points = other.hit_points;
	energy_points = other.energy_points;
	attack_damage = other.attack_damage;
	std::cout << "ClapTrap " << name << " was brought into existence." << std::endl;

}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " was destroyed." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
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

void ClapTrap::attack(const std::string& target)
{
	if (energy_points > 0 && hit_points > 0)
	{
		energy_points -= 1;
		std::cout << "ClapTrap " << name << ", attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
	}	
	else
		std::cout << "ClapTrap " << name << " tried to attack " << target << " but failed due to a lack of energy or hitpoints" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hit_points > 0)
	{
		hit_points -= amount;
		if (hit_points < 0)
			hit_points = 0;
	}
	std::cout << "ClapTrap " << name << ", took " << amount << " damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (energy_points > 0 && hit_points > 0)
	{
		energy_points -= 1;
		hit_points += amount;
		std::cout << "ClapTrap " << name << ", regenerated " << amount << " hit points!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << name << " tried to regenerate but failed due to a lack of emergy or hit points" << std::endl;
}
