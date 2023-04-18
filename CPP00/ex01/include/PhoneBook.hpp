/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/17 19:40:37 by dritsema      #+#    #+#                 */
/*   Updated: 2023/04/18 20:30:52 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
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

#endif // PHONEBOOK_HPP
