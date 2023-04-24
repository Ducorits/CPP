/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zombieHorde.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/23 21:45:54 by dritsema      #+#    #+#                 */
/*   Updated: 2023/04/24 15:13:11 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>

Zombie	*zombieHorde( int N, std::string name )
{
	Zombie	*horde = new Zombie[N]();

	for (int i = 0; i < N; i++)
	{
		horde[i].set_name(name);
	}
	return (horde);
}
