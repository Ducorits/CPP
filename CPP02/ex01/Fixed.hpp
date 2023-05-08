/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 18:07:14 by dritsema      #+#    #+#                 */
/*   Updated: 2023/05/08 17:40:44 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __FIXED_HPP__
#define __FIXED_HPP__

class Fixed
{
	private:
		int	value;
		static const int fractional = 8;
	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed(const int num);
		Fixed(const float numf);
		~Fixed();
		Fixed& operator=(const Fixed &other);
		int		getRawBits(void);
		void	setRawBits(int const raw);
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

#endif /* __FIXED_HPP__ */
