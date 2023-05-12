/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 18:19:59 by dritsema      #+#    #+#                 */
/*   Updated: 2023/05/08 14:16:48 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Fixed.hpp>

	Fixed::Fixed()
	{
		value = 0;
	}

	Fixed::Fixed(const Fixed &other)
	{
		value = other.value;
	}

	Fixed::~Fixed() {}

	Fixed& Fixed::operator=(const Fixed& other)
	{
		if (this != &other)
			value = other.value;
		return (*this);
	}

	int		Fixed::getRawBits(void)
	{
		return (value);
	}

	void	Fixed::setRawBits(int const raw)
	{
		value = raw;
	}