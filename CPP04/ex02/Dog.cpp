/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/29 19:10:24 by dritsema      #+#    #+#                 */
/*   Updated: 2023/06/02 11:49:20 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Dog.hpp>
#include <iostream>

Dog::Dog()
{
	type = "Dog";
	brain = new Brain();
	std::cout << "Dog constructor, Woof!" << std::endl;
}

Dog::Dog(const Dog &other)
{
	type = other.type;
	std::cout << "Dog copy constructor, Bork!" << std::endl;
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog Destructor, HOWL!" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this == &other)
		return (*this);
	type = other.type;
	brain = other.brain;
	std::cout << "Dog copy assigment operator, Bark Bark!" << std::endl;
	return (*this);
}

void Dog::makeSound() const
{
	 std::cout << "Woof!" << std::endl;
}

void	Dog::setBrain(int i, std::string idea)
{
	if (i > 99 || i < 0)
	{
		std::cout << "Invalid index for Brain" << std::endl;
		return ;
	}
	brain->setIdea(i, idea);
}

std::string	Dog::getBrain(int i) const
{
	if (i > 99 || i < 0)
	{
		std::cout << "Invalid index for Brain" << std::endl;
		return (NULL);
	}
	return (brain->getIdea(i));
}

std::string Dog::getType(void) const
{
	std::cout << "Dog getType" << std::endl;
	return (this->type);
}

void Dog::setType(std::string str)
{
	std::cout << "Dog setType" << std::endl;
	this->type = str;
}
