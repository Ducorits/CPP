#pragma once
#ifndef __FORM_HPP__
#define __FORM_HPP__

#include <string>
#include <stdexcept>
#include <iostream>

class Bureaucrat;

class Form
{
public:
	Form(const std::string name, int exec_grade, int sign_grade);
	Form(const Form &other);
	~Form();

	Form &operator=(const Form &other);

	std::string getName(void) const;
	int getSignGrade(void) const;
	int getExecGrade(void) const;
	bool getSign(void) const;

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
	const std::string _name;
	const int _sign_grade;
	const int _exec_grade;
	bool _signed;
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif /* __FORM_HPP__ */
