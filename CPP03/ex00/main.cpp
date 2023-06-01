/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 18:05:40 by dritsema      #+#    #+#                 */
/*   Updated: 2023/06/01 19:54:17 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ClapTrap.hpp>
#include <iostream>

int	main(void)
{
	ClapTrap a = ClapTrap("Garty");
	ClapTrap b = a;

	a.attack("Henry");
	a.takeDamage(9);
	a.beRepaired(9);
	a.attack("Lodewijk");

	int i = 0;
	while (i < 20)
	{
		b.attack("Hans");
		i++;
	}
	std::cout << i << " attacks have been tried" << std::endl;
	return (0);
}
