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

		std::string getname(void) const;
		int getGrade(void) const;

		void	promote(void);
		void	demote(void);

		class GradeTooHighException : public std::exception
		{
			public:
			char * what ()
			{
				return ("Grade Too High!");
			}
		};

		class GradeTooLowException : public std::exception
		{
			public:
			char * what ()
			{
				return ("Grade Too Low!");
			}
		};

	protected:

	private:
		const std::string name;
		int grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif /* __BUREACRAT_HPP__ */
