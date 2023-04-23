/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   randomChump.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/23 21:16:29 by dritsema      #+#    #+#                 */
/*   Updated: 2023/04/23 21:23:12 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>

void	randomChump( std::string name )
 {
	Zombie zomb = Zombie(name);
	zomb.announce();
 }
