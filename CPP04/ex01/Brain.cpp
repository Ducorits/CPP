/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/31 12:32:57 by dritsema      #+#    #+#                 */
/*   Updated: 2023/05/31 16:24:36 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Brain.hpp>
#include <iostream>
#include <string>

Brain::Brain()
{
	std::cout << "Brain constructor" << std::endl;
}

Brain::Brain(const Brain &other)
{
	*this = other;
	std::cout << "Brain copy constructor" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain Destructor" << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
	std::cout << "Brain copy assigment operator" << std::endl;
	if (this == &other)
		return (*this);
	for (int i = 0; i < 100; i++)
	{
		ideas[i] = other.ideas[i];
	}
	return (*this);
}

void	Brain::setIdea(int i, std::string idea)
{
	if (i > 99 || i < 0)
	{
		std::cout << "Invalid idea index" << std::endl;
		return ;
	}
	ideas[i] = idea;
}

std::string	Brain::getIdea(int i)
{
	if (i > 99)
		return (ideas[99]);
	else if (i < 0)
		return (ideas[0]);
	return (ideas[i]);
}
