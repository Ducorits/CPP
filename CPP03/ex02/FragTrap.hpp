/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/26 13:23:41 by dritsema      #+#    #+#                 */
/*   Updated: 2023/06/01 21:13:24 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __FRAGTRAP_HPP__
#define __FRAGTRAP_HPP__

#include <ClapTrap.hpp>

class FragTrap : public ClapTrap
{
	private:
		std::string name;
		int	hit_points;
		int energy_points;
		int attack_damage;
	public:
		FragTrap();
		FragTrap(const std::string& str);
		FragTrap(const FragTrap &other);
		~FragTrap();
		FragTrap& operator=(const FragTrap& other);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void highFivesGuys(void);
};

#endif /* __FRAGTRAP_HPP__ */
