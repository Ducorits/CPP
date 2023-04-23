/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   newZombie.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/23 21:16:38 by dritsema      #+#    #+#                 */
/*   Updated: 2023/04/23 21:22:06 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>

 Zombie* newZombie( std::string name )
 {
	Zombie *zomb = new Zombie(name);
	return (zomb);
 }
