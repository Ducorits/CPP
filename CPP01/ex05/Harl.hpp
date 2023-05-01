/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/29 16:03:46 by dritsema      #+#    #+#                 */
/*   Updated: 2023/05/01 18:36:33 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __HARL_HPP__
#define __HARL_HPP__

#include <string>

class Harl
{
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
	public:
		void complain(std::string level);
};

typedef void (Harl::*t_func)(void);

#endif /* __HARL_HPP__ */
