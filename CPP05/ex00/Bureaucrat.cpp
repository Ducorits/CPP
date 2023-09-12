#include <Bureaucrat.hpp>
#include <iostream>

Bureaucrat::Bureaucrat(const std::string name, int grade)
{
	if (grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	else if (grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{

}

Bureaucrat::~Bureaucrat()
{

}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{

}

std::string Bureaucrat::getname(void) const
{
	return (this->name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getname() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (os);
}
