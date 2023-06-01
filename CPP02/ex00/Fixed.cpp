/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 18:19:59 by dritsema      #+#    #+#                 */
/*   Updated: 2023/06/01 15:06:06 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Fixed.hpp>
#include <iostream>

Fixed::Fixed()
{
	value = 0;
	std::cout << "Fixed Default Constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	value = other.value;
	std::cout << "Fixed Copy Constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Fixed Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		value = other.value;
	return (*this);
}

int		Fixed::getRawBits(void)
{
	std::cout << "getRawBits member function called" << std::endl;
	return (value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	value = raw;
}
