/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/29 18:11:48 by dritsema      #+#    #+#                 */
/*   Updated: 2023/05/29 19:46:19 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Animal.hpp>
#include <iostream>

Animal::Animal()
{
	std::cout << "Animal constructor" << std::endl;
}

Animal::Animal(const Animal &other)
{
	type = other.type;
	std::cout << "Animal copy constructor" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal Destructor" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	if (this != &other)
	{
		type = other.type;
	}
	std::cout << "Animal copy assigment operator" << std::endl;
	return (*this);
}

std::string Animal::getType(void) const
{
	std::cout << "getType" << std::endl;
	return (this->type);
}

void Animal::setType(std::string str)
{
	std::cout << "setType" << std::endl;
	this->type = str;
}

void Animal::makeSound() const
{
	if (this->type == "Cat")
		std::cout << "Meeeooow!" << std::endl;
	else if (this->type == "Dog")
		std::cout << "Woof!" << std::endl;
	else
	 std::cout << "Generic animal sounds" << std::endl;
}
