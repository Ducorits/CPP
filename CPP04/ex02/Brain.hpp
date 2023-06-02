/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/31 12:33:12 by dritsema      #+#    #+#                 */
/*   Updated: 2023/05/31 15:52:20 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __BRAIN_HPP__
#define __BRAIN_HPP__

#include <string>

class Brain
{
	public:
		Brain();
		Brain(const Brain &other);
		virtual ~Brain();

		Brain& operator=(const Brain& other);
		
		void setIdea(int i, std::string idea);
		std::string getIdea(int i);

	protected:
		std::string ideas[100];

	private:
};

#endif /* __BRAIN_HPP__ */

