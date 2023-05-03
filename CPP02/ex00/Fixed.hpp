/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 18:07:14 by dritsema      #+#    #+#                 */
/*   Updated: 2023/05/03 18:22:01 by dritsema      ########   odam.nl         */
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
		~Fixed();
		Fixed& operator=(const Fixed& other);
		int		getRawBits(void);
		void	setRawBits(int const raw);
};

#endif /* __FIXED_HPP__ */
