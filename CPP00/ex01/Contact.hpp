/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/18 13:43:04 by dritsema      #+#    #+#                 */
/*   Updated: 2023/04/26 10:55:58 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __CONTACT_H__
#define __CONTACT_H__
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

	private:
		std::string attributes[5];
};

#endif /* __CONTACT_H__ */
