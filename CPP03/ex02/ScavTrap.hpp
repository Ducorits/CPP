/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/19 18:07:32 by dritsema      #+#    #+#                 */
/*   Updated: 2023/06/02 13:42:26 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __SCAVTRAP_HPP__
#define __SCAVTRAP_HPP__

#include <ClapTrap.hpp>

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(const std::string& str);
		ScavTrap(const ScavTrap &other);
		~ScavTrap();

		ScavTrap& operator=(const ScavTrap& other);

		void attack(const std::string& target);
		void guardGate();

	protected:

	private:
};

#endif /* __SCAVTRAP_HPP__ */
