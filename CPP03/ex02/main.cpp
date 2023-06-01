/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 18:05:40 by dritsema      #+#    #+#                 */
/*   Updated: 2023/06/01 21:16:04 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ClapTrap.hpp>
#include <ScavTrap.hpp>
#include <FragTrap.hpp>
#include <iostream>

int	main(void)
{
	ClapTrap a = ClapTrap("Garty");
	ScavTrap b = ScavTrap("Solomon");
	FragTrap c = FragTrap("Michael");
	
	a.attack("Henry");
	a.takeDamage(9);
	a.beRepaired(9);
	a.attack("Lodewijk");
	b.attack("Henry");
	b.takeDamage(9);
	b.beRepaired(9);
	c.attack("Henry");
	c.takeDamage(10);
	c.beRepaired(10);

	int i = 0;
	while (i < 50)
	{
		b.attack("Hans");
		c.attack("Terrence");
		i++;
	}
	std::cout << "They tried to attack " << i << " times" << std::endl;
	c.highFivesGuys();
	b.guardGate();
	return (0);
}
