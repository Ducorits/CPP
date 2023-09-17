#pragma once
#ifndef __FORM_HPP__
#define __FORM_HPP__

#include <string>
#include <stdexcept>
#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
	public:
		Form(const std::string name, int grade);
		Form(const Form &other);
		~Form();

		Form& operator=(const Form& other);

		std::string getName(void) const;
		int getGrade(void) const;
		bool getSign(void) const;

		void beSigned(Bureaucrat& bureaucrat);

		class GradeTooHighException : public std::exception
		{
			public:
			const char * what() const throw()
			{
				return "Grade Too High!";
			}
		};

		class GradeTooLowException : public std::exception
		{
			public:
			const char * what() const throw()
			{
				return "Grade Too Low!";
			}
		};

	protected:

	private:
		const std::string name;
		const int grade;
		bool sig_ned;
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif /* __FORM_HPP__ */
