/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/29 19:10:24 by dritsema      #+#    #+#                 */
/*   Updated: 2023/05/30 17:01:37 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Dog.hpp>
#include <iostream>

Dog::Dog()
{
	type = "Dog";
	std::cout << "Dog constructor, Woof!" << std::endl;
}

Dog::Dog(const Dog &other)
{
	type = other.type;
	std::cout << "Dog copy constructor, Bork!" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor, HOWL!" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		type = other.type;
	}
	std::cout << "Dog copy assigment operator, Bark Bark!" << std::endl;
	return (*this);
}

void Dog::makeSound() const
{
	 std::cout << "Woof!" << std::endl;
}
