/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/17 19:40:37 by dritsema      #+#    #+#                 */
/*   Updated: 2023/04/23 20:20:01 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __PHONEBOOK_H__
#define __PHONEBOOK_H__

#include <Contact.hpp>

class PhoneBook {
	private:
		Contact contacts[8];
		int		index;

	public:
		void	add(void);
		void	search(void);
		PhoneBook(void);
};

#endif /* __PHONEBOOK_H__ */
