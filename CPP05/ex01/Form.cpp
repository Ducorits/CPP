#include <Form.hpp>
#include <Bureaucrat.hpp>
#include <iostream>

Form::Form(const std::string n, int sg, int eg) : _name(n), _sign_grade(sg), _exec_grade(eg), _signed(false)
{
	if (this->_sign_grade < 1 || this->_exec_grade < 1)
	{
		throw Form::GradeTooHighException();
	}
	else if (this->_sign_grade > 150 || this->_exec_grade > 150)
	{
		throw Form::GradeTooLowException();
	}
	std::cout << "Form constructor" << std::endl;
}

Form::Form(const Form &other) : _name(other.getName()), _sign_grade(other.getSignGrade()), _exec_grade(getExecGrade()), _signed(other.getSign())
{
	std::cout << "Form copy constructor" << std::endl;
}

Form::~Form()
{
	std::cout << "Form destructor" << std::endl;
}

std::string Form::getName(void) const
{
	return (this->_name);
}

int Form::getSignGrade(void) const
{
	return (this->_sign_grade);
}

int Form::getExecGrade(void) const
{
	return (this->_exec_grade);
}

bool Form::getSign(void) const
{
	return (this->_signed);
}

Form &Form::operator=(const Form &other)
{
	(*this)._signed = other.getSign();
	return (*this);
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade Too High!";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade Too Low!";
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_sign_grade)
		this->_signed = true;
	else
		throw Form::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << form.getName() << ":\n - Form sign grade: " << form.getSignGrade() << "\n - Form exec grade: " << form.getExecGrade() << "\n - Signature: " << form.getSign();
	return (os);
}
