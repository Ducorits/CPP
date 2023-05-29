/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/29 18:12:12 by dritsema      #+#    #+#                 */
/*   Updated: 2023/05/29 19:45:57 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __ANIMAL_HPP__
#define __ANIMAL_HPP__

#include <string>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(const Animal &other);
		~Animal();
		Animal& operator=(const Animal& other);
		void makeSound(void) const;
		std::string getType(void) const;
		void setType(std::string str);
};

#endif /* __ANIMAL_HPP__ */
