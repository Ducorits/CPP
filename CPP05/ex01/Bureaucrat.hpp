#pragma once
#ifndef __BUREACRAT_HPP__
#define __BUREACRAT_HPP__

#include <string>
#include <stdexcept>
#include <iostream>

class Bureaucrat
{
	public:
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		~Bureaucrat();

		Bureaucrat& operator=(const Bureaucrat& other);

		std::string getName(void) const;
		int getGrade(void) const;

		void	promote(void);
		void	demote(void);

		void	signForm(Form& form);


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
		int grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif /* __BUREACRAT_HPP__ */
