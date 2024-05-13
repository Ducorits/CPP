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

		std::string getName(void) const;
		int getSignGrade(void) const;
		int getExecGrade(void) const;
		bool getSign(void) const;
		std::string getTarget(void) const;

		void beSigned(Bureaucrat &bureaucrat);

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
	private:
		const std::string _target;
};

std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &form);

#endif /* __PRESIDENTIALPARDONFORM_HPP__ */