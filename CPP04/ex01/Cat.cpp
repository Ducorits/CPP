/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/29 19:04:41 by dritsema      #+#    #+#                 */
/*   Updated: 2023/06/02 11:14:28 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Cat.hpp>
#include <iostream>

Cat::Cat()
{
	type = "Cat";
	brain = new Brain();
	std::cout << "Cat constructor Mreeoww!" << std::endl;
}

Cat::Cat(const Cat &other)
{
	*this = other;
	delete brain;
	std::cout << "Cat copy constructor, Prrrrrr" << std::endl;
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat Destructor, Meowie" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
		return (*this);
	type = other.type;
	brain = other.brain;
	std::cout << "Cat copy assigment operator, Meeeooow!" << std::endl;
	return (*this);
}

void Cat::makeSound() const
{
	 std::cout << "Meeeooow!" << std::endl;
}

void	Cat::setBrain(int i, std::string idea)
{
	if (i > 99 || i < 0)
	{
		std::cout << "Invalid index for Brain" << std::endl;
		return ;
	}
	brain->setIdea(i, idea);
}

std::string	Cat::getBrain(int i)
{
	if (i > 99 || i < 0)
	{
		std::cout << "Invalid index for Brain" << std::endl;
		return (NULL);
	}
	return (brain->getIdea(i));
}
