#include <Form.hpp>
#include <iostream>
#include "Bureaucrat.hpp"

Form::Form(const std::string n, int g) : name(n), grade(g)
{
	if (this->grade < 1)
	{
		throw Form::GradeTooHighException();
	}
	else if (this->grade > 150)
	{
		throw Form::GradeTooLowException();
	}
	std::cout << "Form constructor" << std::endl;
}

Form::Form(const Form &other)
{
	*this = other;
	std::cout << "Form copy constructor" << std::endl;
}

Form::~Form()
{
	std::cout << "Form destructor" << std::endl;
}

Form& Form::operator=(const Form& other)
{
	*this = other;
	return (*this);
}

std::string Form::getName(void) const
{
	return (this->name);
}

int Form::getGrade(void) const
{
	return (this->grade);
}

bool Form::getSign(void) const
{
	return (this->sig_ned);
}

void Form::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= this->grade)
		this->sig_ned = true;
	else
		throw Form::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Form& Form)
{
	os << Form.getName() << ", Form grade " << Form.getGrade() << " Signature.";
	return (os);
}
