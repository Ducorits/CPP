/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongAnimal.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/30 12:55:17 by dritsema      #+#    #+#                 */
/*   Updated: 2023/06/02 12:10:35 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <WrongAnimal.hpp>
#include <iostream>

WrongAnimal::WrongAnimal()
{
	type = "";
	std::cout << "WrongAnimal constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	type = other.type;
	std::cout << "WrongAnimal copy constructor" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this != &other)
	{
		type = other.type;
	}
	std::cout << "WrongAnimal copy assigment operator" << std::endl;
	return (*this);
}

std::string WrongAnimal::getType(void) const
{
	std::cout << "Wrong animal getType" << std::endl;
	return (this->type);
}

void WrongAnimal::setType(std::string str)
{
	std::cout << "Wrong animal setType" << std::endl;
	this->type = str;
}

void WrongAnimal::makeSound() const
{
	 std::cout << "Generic Wrong animal * silence *" << std::endl;
}
