/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/29 18:56:03 by dritsema      #+#    #+#                 */
/*   Updated: 2023/05/29 19:37:18 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __DOG_HPP__
#define __DOG_HPP__

#include <string>
#include <Animal.hpp>

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog &other);
		~Dog();
		Dog& operator=(const Dog& other);
};

#endif /* __DOG_HPP__ */
