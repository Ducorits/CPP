/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/29 19:04:41 by dritsema      #+#    #+#                 */
/*   Updated: 2023/05/29 19:46:54 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Cat.hpp>
#include <iostream>

Cat::Cat()
{
	type = "Cat";
	std::cout << "Cat constructor Mreeoww!" << std::endl;
}

Cat::Cat(const Cat &other)
{
	type = other.type;
	std::cout << "Cat copy constructor, Prrrrrr" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor, Meowie" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		type = other.type;
	}
	std::cout << "Cat copy assigment operator, Meeeooow!" << std::endl;
	return (*this);
}

