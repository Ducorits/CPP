/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 18:19:59 by dritsema      #+#    #+#                 */
/*   Updated: 2023/06/01 15:21:52 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Fixed.hpp>
#include <cmath>
#include <iostream>

Fixed::Fixed()
{
	std::cout << "Fixed Default Constructor called" << std::endl;
	value = 0;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Fixed Copy Constructor called" << std::endl;
	value = other.value;

}

Fixed::Fixed(const int num)
{
	std::cout << "Fixed Int Constructor called" << std::endl;
	value = num << fractional;
}

Fixed::Fixed(const float numf)
{
	std::cout << "Fixed Float Constructor called" << std::endl;
	value = static_cast<int>(roundf(numf * (1 << fractional)));
}

Fixed::~Fixed()
{
	std::cout << "Fixed Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this !=& other)
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

float	Fixed::toFloat( void ) const
{
	std::cout << "toFloat member function called" << std::endl;
	return (static_cast<float>(value) / (1 << fractional));
}

int		Fixed::toInt( void ) const
{
	std::cout << "toInt member funtion called" << std::endl;
	return (value >> fractional);
}

bool Fixed::operator==(const Fixed& other) const
{
	return (value == other.value);
}

bool Fixed::operator<(const Fixed& other) const
{
	return (value < other.value);
}

bool Fixed::operator>(const Fixed& other) const
{
	return (value > other.value);
}

bool Fixed::operator>=(const Fixed& other) const
{
	return (value >= other.value);
}

bool Fixed::operator<=(const Fixed& other) const
{
	return (value <= other.value);
}

bool Fixed::operator!=(const Fixed& other) const
{
	return (value != other.value);	
}

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed tmp = *this;
	tmp.value += other.value;
	return (tmp);
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed tmp = *this;
	tmp.value -= other.value;
	return (tmp);
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed tmp = *this;
	return (tmp.toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed tmp = *this;
	return (tmp.toFloat() / other.toFloat());
}

Fixed& Fixed::operator++(void)
{
	value++;
	return (*this);
}

Fixed& Fixed::operator--(void)
{
	value--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	value--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	value++;
	return tmp;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed_point)
{
	os << fixed_point.toFloat();
	return (os);
}

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return (a);
	else 
		return (b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
if (a > b)
	return (a);
else
	return (b);
}

