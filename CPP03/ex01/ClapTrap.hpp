/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 18:07:14 by dritsema      #+#    #+#                 */
/*   Updated: 2023/06/02 13:29:48 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __CLAPTRAP_HPP__
#define __CLAPTRAP_HPP__

#include <string>

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(const std::string& str);
		ClapTrap(const ClapTrap &other);
		~ClapTrap();

		ClapTrap& operator=(const ClapTrap& other);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
	
	protected:
		std::string name;
		int	hit_points;
		int energy_points;
		int attack_damage;

	private:
};

#endif /* __CLAPTRAP_HPP__ */
