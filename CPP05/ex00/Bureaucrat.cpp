#include <Bureaucrat.hpp>
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

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
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

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade Too High!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade Too Low!";
}

void Bureaucrat::promote(void)
{
	this->grade -= 1;
	if (this->grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
}

void Bureaucrat::demote(void)
{
	this->grade += 1;
	if (this->grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (os);
}
