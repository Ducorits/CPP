/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 18:05:40 by dritsema      #+#    #+#                 */
/*   Updated: 2023/05/19 16:26:40 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ClapTrap.hpp>
#include <iostream>

int	main(void)
{
	ClapTrap a = ClapTrap("Garty");

	a.attack("Henry");
	a.takeDamage(9);
	a.beRepaired(9);
	a.attack("Lodewijk");
	return (0);
}
