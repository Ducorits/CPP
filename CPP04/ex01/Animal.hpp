/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/29 18:12:12 by dritsema      #+#    #+#                 */
/*   Updated: 2023/06/02 11:04:23 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __ANIMAL_HPP__
#define __ANIMAL_HPP__

#include <Brain.hpp>
#include <string>

class Animal
{
	public:
		Animal();
		Animal(const Animal &other);
		virtual ~Animal();

		Animal& operator=(const Animal& other);

		virtual void	makeSound(void) const;
		std::string		getType(void) const;
		void			setType(std::string str);
		virtual void setBrain(int i, std::string idea);
		virtual std::string getBrain(int i);

	protected:
		std::string type;

	private:
		Brain* brain;
};

#endif /* __ANIMAL_HPP__ */
