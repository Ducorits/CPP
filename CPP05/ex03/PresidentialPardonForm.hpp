/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.hpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/13 18:45:20 by dritsema      #+#    #+#                 */
/*   Updated: 2024/06/19 14:46:48 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __PRESIDENTIALPARDONFORM_HPP__
#define __PRESIDENTIALPARDONFORM_HPP__

#include <string>
#include <stdexcept>
#include <iostream>
#include <AForm.hpp>

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm(const std::string target);
	~PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm &other);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

	std::string getTarget(void) const;

protected:
	void action() const;

private:
	const std::string _target;
};

#endif /* __PRESIDENTIALPARDONFORM_HPP__ */