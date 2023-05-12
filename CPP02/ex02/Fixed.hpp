/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 18:07:14 by dritsema      #+#    #+#                 */
/*   Updated: 2023/05/12 17:30:20 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <iostream>

class Fixed
{
	private:
		int	value;
		static const int fractional = 8;
	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed(const int num);
		Fixed(const float numf);
		~Fixed();	
		Fixed& operator=(const Fixed& other);
		bool operator==(const Fixed& other) const;
		bool operator<(const Fixed& other) const;
		bool operator>(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;
		Fixed operator+(const Fixed& other);
		Fixed operator-(const Fixed& other);
		Fixed operator*(const Fixed& other);
		Fixed operator/(const Fixed& other);
		Fixed& operator++(void);
		Fixed& operator--(void);
		Fixed operator--(int);
		Fixed operator++(int);
		int		getRawBits(void);
		void	setRawBits(const int raw);
		float	toFloat( void ) const;
		int		toInt( void ) const;
		static Fixed&	min(Fixed& a, Fixed& b);
		static const Fixed&	min(const Fixed& a, const Fixed& b);
		static Fixed&	max(Fixed& a, Fixed& b);
		static const Fixed&	max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed_point);

#endif /* __FIXED_HPP__ */
