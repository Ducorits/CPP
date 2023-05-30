/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongCat.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/30 13:30:12 by dritsema      #+#    #+#                 */
/*   Updated: 2023/05/30 16:58:58 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __WRONGCAT_HPP__
#define __WRONGCAT_HPP__

#include <string>
#include <WrongAnimal.hpp>

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat &other);
		~WrongCat();

		WrongCat& operator=(const WrongCat& other);

		void makeSound(void) const;

	private:
	
	protected:
};

#endif /* __WRONGCAT_HPP__ */
