/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 15:53:59 by dritsema      #+#    #+#                 */
/*   Updated: 2023/04/24 17:04:03 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __WEAPON_H__
#define __WEAPON_H__

#include <string>

class Weapon
{
	private:
		std::string	type;
	public:
		Weapon();
		Weapon(std::string str);
		~Weapon();
		const std::string	&getType(void);
		void		setType(std::string str);
};

#endif /* __WEAPON_H__ */
