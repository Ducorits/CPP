/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/26 13:23:37 by dritsema      #+#    #+#                 */
/*   Updated: 2023/06/01 21:12:57 by dritsema      ########   odam.nl         */
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

void FragTrap::attack(const std::string& target)
{
	if (energy_points > 0 && hit_points > 0)
	{
		energy_points -= 1;
		std::cout << "FragTrap " << name << ", attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
	}	
	else
		std::cout << "FragTrap " << name << " Cannot attack anymore. He is incapable. No I don't know what happend. Let me be!" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
{
	if (hit_points > 0)
	{
		hit_points -= amount;
		if (hit_points < 0)
			hit_points = 0;
		std::cout << "FragTrap " << name << ", took " << amount << " damage!" << std::endl;
	}
	else
		std::cout << "Poor " << name << " is already broken. Stop it!" << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (energy_points > 0 && hit_points > 0)
	{
		energy_points -= 1;
		hit_points += amount;
		std::cout << "FragTrap " << name << ", regenerated " << amount << " hit points!" << std::endl;
	}
	else
		std::cout << "FragTrap " << name << " is sooooo tired or broken idk, that it cannot possibly even try to repair itself" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << name << " is shaking for a high five. SO excited!" << std::endl;
}
