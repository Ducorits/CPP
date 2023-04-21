/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/18 13:43:04 by dritsema      #+#    #+#                 */
/*   Updated: 2023/04/21 12:28:18 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

enum e_attribute {
	FIRST_NAME,
	LAST_NAME,
	NICKNAME,
	PHONE_NUMBER,
	DARKEST_SECRET
};

class Contact
{
	public:
		void		print(void);
		void		setAttribute(e_attribute attr, std::string str);
		std::string	getAttribute(e_attribute attr);

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
		std::string attributes[5] = {"", "", "", "", ""};
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
};
