/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/29 18:56:17 by dritsema      #+#    #+#                 */
/*   Updated: 2023/05/29 19:37:24 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __CAT_HPP__
#define __CAT_HPP__

#include <string>
#include <Animal.hpp>

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat &other);
		~Cat();
		Cat& operator=(const Cat& other);
};

#endif /* __CAT_HPP__ */

