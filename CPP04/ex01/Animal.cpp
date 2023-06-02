/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   A_Animal.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/29 18:11:48 by dritsema      #+#    #+#                 */
/*   Updated: 2023/06/02 11:17:56 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Animal.hpp>
#include <iostream>

Animal::Animal()
{
	type = "Animal";
	brain = new Brain();
	std::cout << "Animal constructor" << std::endl;
}

Animal::Animal(const Animal &other)
{
	*this = other;
	std::cout << "Animal copy constructor" << std::endl;
}

Animal::~Animal()
{
	delete brain;
	std::cout << "Animal Destructor" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	if (this == &other)
		return (*this);
	type = other.type;
	brain = other.brain;
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
	 std::cout << "Animal * silence *" << std::endl;
}

void	Animal::setBrain(int i, std::string idea)
{
	if (i > 99 || i < 0)
	{
		std::cout << "Invalid index for Brain" << std::endl;
		return ;
	}
	brain->setIdea(i, idea);
}

std::string	Animal::getBrain(int i)
{
	if (i > 99 || i < 0)
	{
		std::cout << "Invalid index for Brain" << std::endl;
		return (NULL);
	}
	return (brain->getIdea(i));
}
