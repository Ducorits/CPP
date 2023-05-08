/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 18:19:59 by dritsema      #+#    #+#                 */
/*   Updated: 2023/05/08 17:47:07 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Fixed.hpp>
#include <cmath>

Fixed::Fixed()
{
	value = 0;
}

Fixed::Fixed(const Fixed &other)
{
	value = other.value;
}

Fixed::Fixed(const int num)
{
	value = num << fractional;
}

Fixed::Fixed(const float numf)
{
	value = static_cast<int>(roundf(numf * (1 << fractional)));
}

Fixed::~Fixed() {}

Fixed& Fixed::operator=(const Fixed &other)
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

float	Fixed::toFloat( void ) const
{
	return ();
}

int		Fixed::toInt( void ) const
{
	return ();
}
