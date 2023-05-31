/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongCat.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/30 13:29:46 by dritsema      #+#    #+#                 */
/*   Updated: 2023/05/30 17:04:51 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <WrongCat.hpp>
#include <iostream>

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << "WrongCat constructor Mreeoww!" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other)
{
	*this = other;
	std::cout << "WrongCat copy constructor, Prrrrrr" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor, Meowie" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	if (this == &other)
		return (*this);
	type = other.type;
	std::cout << "WrongCat copy assigment operator, Meeeooow!" << std::endl;
	return (*this);
}

void WrongCat::makeSound() const
{
	 std::cout << "Weird Meeow!" << std::endl;
}
