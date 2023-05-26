/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/26 13:23:37 by dritsema      #+#    #+#                 */
/*   Updated: 2023/05/26 13:34:48 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <FragTrap.hpp>
#include <iostream>

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
	if (this != &other)
	{
		name = other.name;
		hit_points = other.hit_points;
		energy_points = other.energy_points;
		attack_damage = other.attack_damage;
	}
	std::cout << name << " was copied. So now there could be multiple " << name << "s." << std::endl;
	return (*this);
}

void FragTrap::attack(const std::string& target)
{
	if (energy_points > 0 && hit_points > 0)
	{
		energy_points -= 1;
		std::cout << "FragTrap " << name << ", attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
	}	
}

void FragTrap::takeDamage(unsigned int amount)
{
	if (hit_points > 0)
	{
		hit_points -= amount;
		if (hit_points < 0)
			hit_points = 0;
	}
	std::cout << "FragTrap " << name << ", took " << amount << " damage!" << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (energy_points > 0 && hit_points > 0)
	{
		energy_points -= 1;
		hit_points += amount;
	}
	std::cout << "FragTrap " << name << ", regenerated " << amount << " hit points!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << name << " is shaking for a high five. SO excited!" << std::endl;
}
