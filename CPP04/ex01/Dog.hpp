/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/29 18:56:03 by dritsema      #+#    #+#                 */
/*   Updated: 2023/06/02 14:14:40 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __DOG_HPP__
#define __DOG_HPP__

#include <string>
#include <Animal.hpp>
#include <Brain.hpp>

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog &other);
		~Dog();

		Dog& operator=(const Dog& other);

		void makeSound(void) const;

	protected:

	private:
		Brain* brain;
};

#endif /* __DOG_HPP__ */
