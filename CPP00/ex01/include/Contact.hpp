/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/18 13:43:04 by dritsema      #+#    #+#                 */
/*   Updated: 2023/04/20 14:05:51 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Contact
{
	public:
		void		print(void);
		void		setFirstName(std::string str);
		std::string	getFirstName(void);
		void		setLasttName(std::string str);
		std::string	getLasttName(void);
		void		setNickname(std::string str);
		std::string	getNickname(void);
		void		setPhoneNumber(std::string str);
		std::string	getPhoneNumber(void);
		void		setDarkestSecret(std::string str);
		std::string	getDarkestSecret(void);

	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
};
