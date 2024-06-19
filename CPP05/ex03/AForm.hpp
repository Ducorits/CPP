#pragma once
#ifndef __AFORM_HPP__
#define __AFORM_HPP__

#include <string>
#include <stdexcept>
#include <iostream>

class Bureaucrat;

class AForm
{
public:
	AForm(const std::string name, int exec_grade, int sign_grade);
	AForm(const AForm &other);
	virtual ~AForm();

	AForm &operator=(const AForm &other);

	std::string getName(void) const;
	int getSignGrade(void) const;
	int getExecGrade(void) const;
	bool getSign(void) const;

	void execute(Bureaucrat const & executor) const;
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

	class FormNotSignedException : public std::exception
	{
	public:
		const char *what() const throw();
	};

protected:
	virtual void action() const = 0;
private:
	const std::string _name;
	const int _sign_grade;
	const int _exec_grade;
	bool _signed;
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif /* __AFORM_HPP__ */
