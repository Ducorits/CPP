/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/29 18:56:17 by dritsema      #+#    #+#                 */
/*   Updated: 2023/05/31 15:21:37 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __CAT_HPP__
#define __CAT_HPP__

#include <string>
#include <Animal.hpp>
#include <Brain.hpp>

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat &other);
		~Cat();

		Cat& operator=(const Cat& other);

		void makeSound(void) const;
		void setBrain(int i, std::string idea);
		std::string getBrain(int i);

	protected:
	
	private:
		Brain* brain;
};

#endif /* __CAT_HPP__ */
