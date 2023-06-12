/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   A_Animal.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/29 18:11:48 by dritsema      #+#    #+#                 */
/*   Updated: 2023/06/12 18:15:04 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <A_Animal.hpp>
#include <iostream>

A_Animal::A_Animal()
{
	type = "A_Animal";
	brain = new Brain();
	std::cout << "A_Animal constructor" << std::endl;
}

A_Animal::A_Animal(const A_Animal &other)
{
	*this = other;
	std::cout << "A_Animal copy constructor" << std::endl;
}

A_Animal::~A_Animal()
{
	delete brain;
	std::cout << "A_Animal Destructor" << std::endl;
}

A_Animal& A_Animal::operator=(const A_Animal& other)
{
	if (this == &other)
		return (*this);
	type = other.type;
	brain = other.brain;
	std::cout << "A_Animal copy assigment operator" << std::endl;
	return (*this);
}

std::string A_Animal::getType(void) const
{
	std::cout << "A_Animal getType" << std::endl;
	return (this->type);
}

void A_Animal::setType(std::string str)
{
	std::cout << "A_Animal setType" << std::endl;
	this->type = str;
}
