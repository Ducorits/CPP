/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/19 18:07:32 by dritsema      #+#    #+#                 */
/*   Updated: 2023/05/26 15:19:11 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __SCAVTRAP_HPP__
#define __SCAVTRAP_HPP__

#include <ClapTrap.hpp>

class ScavTrap : virtual public ClapTrap
{
	private:
		std::string name;
		int	hit_points;
		int energy_points;
		int attack_damage;
	public:
		ScavTrap(const std::string& str);
		ScavTrap(const ScavTrap &other);
		~ScavTrap();
		ScavTrap& operator=(const ScavTrap& other);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void guardGate();
};

#endif /* __SCAVTRAP_HPP__ */
