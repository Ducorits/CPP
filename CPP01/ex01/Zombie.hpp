/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/23 21:10:56 by dritsema      #+#    #+#                 */
/*   Updated: 2023/04/23 22:19:03 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

#include <string>

class Zombie
{
private:
	std::string	name;
public:
	Zombie(std::string n = "Zombie");
	~Zombie();
	void	announce( void );
	void	set_name(std::string n);
};

Zombie	*zombieHorde( int N, std::string name );

#endif /* __ZOMBIE_H__ */
