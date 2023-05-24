/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 18:05:40 by dritsema      #+#    #+#                 */
/*   Updated: 2023/05/24 17:04:31 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ClapTrap.hpp>
#include <ScavTrap.hpp>
#include <iostream>

int	main(void)
{
	ClapTrap a = ClapTrap("Garty");
	ScavTrap b = ScavTrap("Solomon");

	a.attack("Henry");
	a.takeDamage(9);
	a.beRepaired(9);
	a.attack("Lodewijk");
	b.attack("Henry");
	b.guardGate();

	for (int i = 0; i < 50; i++)
	{
		b.attack("Hans");
		std::cout << i << std::endl;
	}
	return (0);
}
