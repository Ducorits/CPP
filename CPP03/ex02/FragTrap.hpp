/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/26 13:23:41 by dritsema      #+#    #+#                 */
/*   Updated: 2023/06/02 13:38:42 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __FRAGTRAP_HPP__
#define __FRAGTRAP_HPP__

#include <ClapTrap.hpp>

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(const std::string& str);
		FragTrap(const FragTrap &other);
		~FragTrap();

		FragTrap& operator=(const FragTrap& other);

		void highFivesGuys(void);

	protected:

	private:
};

#endif /* __FRAGTRAP_HPP__ */
