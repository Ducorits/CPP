/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   A_Animal.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/29 18:12:12 by dritsema      #+#    #+#                 */
/*   Updated: 2023/06/02 12:01:28 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __A_ANIMAL_HPP__
#define __A_ANIMAL_HPP__

#include <Brain.hpp>
#include <string>

class A_Animal
{
	public:
		A_Animal();
		A_Animal(const A_Animal &other);
		virtual ~A_Animal();

		A_Animal& operator=(const A_Animal& other);

		virtual void	makeSound(void) const = 0;
		virtual std::string		getType(void) const = 0;
		virtual void			setType(std::string str) = 0;
		virtual void setBrain(int i, std::string idea) = 0;
		virtual std::string getBrain(int i) const = 0;

	protected:
		std::string type;

	private:
		Brain* brain;
};

#endif /* __A_ANIMAL_HPP__ */
