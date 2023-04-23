/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/23 21:25:37 by dritsema      #+#    #+#                 */
/*   Updated: 2023/04/23 22:25:14 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>

int	main()
{
	Zombie *horde;
	int		horde_size = 20;

	horde = zombieHorde(horde_size, "Roger");
	for (int i = 0; i < horde_size; i++)
	{
		horde[i].announce();
	}
	delete horde;
	return (0);
}
