#pragma once
#ifndef __BUREACRAT_HPP__
#define __BUREACRAT_HPP__

#include <string>
#include <stdexcept>

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		~Bureaucrat();

		Bureaucrat& operator=(const Bureaucrat& other);

		std::string getname();
		int getGrade();

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

#endif /* __BUREACRAT_HPP__ */
