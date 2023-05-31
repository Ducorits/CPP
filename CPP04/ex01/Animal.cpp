/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/29 18:11:48 by dritsema      #+#    #+#                 */
/*   Updated: 2023/05/30 16:48:30 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Animal.hpp>
#include <iostream>

Animal::Animal()
{
	type = "Animal";
	std::cout << "Animal constructor" << std::endl;
}

Animal::Animal(const Animal &other)
{
	*this = other;
	std::cout << "Animal copy constructor" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal Destructor" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	if (this == &other)
		return (*this);
	type = other.type;
	std::cout << "Animal copy assigment operator" << std::endl;
	return (*this);
}

std::string Animal::getType(void) const
{
	std::cout << "Animal getType" << std::endl;
	return (this->type);
}

void Animal::setType(std::string str)
{
	std::cout << "Animal setType" << std::endl;
	this->type = str;
}

void Animal::makeSound() const
{
	 std::cout << "Generic animal sounds" << std::endl;
}
