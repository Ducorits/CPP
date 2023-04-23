/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/23 21:25:37 by dritsema      #+#    #+#                 */
/*   Updated: 2023/04/23 21:44:13 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>

int	main()
{
	Zombie	*harry;
	Zombie	*chump;

	randomChump("Gerard");
	harry = newZombie("Harry");
	harry->announce();
	chump = newZombie("Chump");
	chump->announce();


	delete harry;
	delete chump;
	return (0);
}
