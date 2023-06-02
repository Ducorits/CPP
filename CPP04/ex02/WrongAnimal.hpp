/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongAnimal.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/30 12:57:52 by dritsema      #+#    #+#                 */
/*   Updated: 2023/05/30 16:55:24 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __WRONGANIMAL_HPP__
#define __WRONGANIMAL_HPP__

#include <string>

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &other);
		~WrongAnimal();

		WrongAnimal& operator=(const WrongAnimal& other);

		void makeSound(void) const;
		std::string getType(void) const;
		void setType(std::string str);

	protected:
		std::string type;
	
	private:
};

#endif /* __WRONGANIMAL_HPP__ */
