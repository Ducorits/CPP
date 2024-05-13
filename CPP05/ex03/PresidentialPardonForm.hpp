/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.hpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/13 18:45:20 by dritsema      #+#    #+#                 */
/*   Updated: 2024/05/13 19:13:24 by dritsema      ########   odam.nl         */
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
		PresidentialPardonForm(const PresidentialPardonForm &other);
		~PresidentialPardonForm();

		PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

		std::string getTarget(void) const;

		class GradeTooHighException : public std::exception
		{
		public:
			const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
		public:
			const char *what() const throw();
		};

	protected:
		void executeForm() const;
	private:
		const std::string _target;
};

std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &form);

#endif /* __PRESIDENTIALPARDONFORM_HPP__ */