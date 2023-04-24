/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanA.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 15:54:00 by dritsema      #+#    #+#                 */
/*   Updated: 2023/04/24 17:04:27 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __HUMANA_H__
#define __HUMANA_H__

#include <string>
#include <Weapon.hpp>

class HumanA
{
	private:
		std::string	name;
		Weapon		*weapon;
	public:
		HumanA(std::string n, Weapon &w);
		~HumanA();
		void	attack(void);
};

#endif /* __HUMANA_H__ */
