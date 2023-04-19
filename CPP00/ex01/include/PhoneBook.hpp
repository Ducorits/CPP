/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/17 19:40:37 by dritsema      #+#    #+#                 */
/*   Updated: 2023/04/19 16:52:05 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <Contact.hpp>

class PhoneBook {
	private:
		Contact contacts[8];
		int		index;

	public:
		void	add(void);
		void	search(void);
		void	exit(void);
		PhoneBook(void);
};
