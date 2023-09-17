#include <Bureaucrat.hpp>
#include <Form.hpp>
#include <iostream>

Bureaucrat::Bureaucrat(const std::string n, int g) : name(n), grade(g)
{
	if (this->grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	else if (this->grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	std::cout << "Bureaucrat constructor" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
	*this = other;
	std::cout << "Bureaucrat copy constructor" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	*this = other;
	return (*this);
}

std::string Bureaucrat::getName(void) const
{
	return (this->name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

void	Bureaucrat::promote(void)
{
	this->grade -= 1;
	if (this->grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
}

void	Bureaucrat::demote(void)
{
	this->grade += 1;
	if (this->grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
}

void	Bureaucrat::signForm(Form& form)
{
	try {
		form.beSigned(*this);
		std::cout << this->name << " signed " << form.getName();
	}
	catch (const Form::GradeTooLowException& e) {
		std::cout << this->name << " couldn't sign " << form.getName() << " because " << e.what();
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (os);
}
