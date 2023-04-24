/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 15:54:05 by dritsema      #+#    #+#                 */
/*   Updated: 2023/04/24 17:04:32 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __HUMANB_H__
#define __HUMANB_H__

#include <string>
#include <Weapon.hpp>

class HumanB
{
	private:
		std::string	name;
		Weapon		*weapon;
	public:
		HumanB(std::string n);
		~HumanB();
		void	attack(void);
		void	setWeapon(Weapon &w);
};

#endif /* __HUMANB_H__ */
