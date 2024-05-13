#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat *createBureaucrat(const std::string name, int grade)
{
	try
	{
		Bureaucrat *crat = new Bureaucrat(name, grade);
		std::cout << *crat << std::endl;
		return (crat);
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "Exception! " << e.what() << std::endl;
		return nullptr;
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "Exception! " << e.what() << std::endl;
		return nullptr;
	}
}

void trySignForm(Bureaucrat &crat, AForm &form)
{
	try
	{
		crat.signForm(form);
	}
	catch (const AForm::GradeTooHighException &e)
	{
		std::cout << "Exception! " << e.what() << std::endl;
	}
	catch (const AForm::GradeTooLowException &e)
	{
		std::cout << "Exception! " << e.what() << std::endl;
	}
}

void tryPromote(Bureaucrat &bureaucrat)
{
	try
	{
		std::cout << bureaucrat.getName() << " is being promoted!" << std::endl;
		bureaucrat.promote();
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		std::cout << bureaucrat.getName() << " Could not be promoted. You can't get better than this! It is physically impossible!" << std::endl;
	}
}

void tryDemote(Bureaucrat &bureaucrat)
{
	try
	{
		bureaucrat.demote();
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cout << bureaucrat.getName() << " Could not be demoted. Any lower and they won't be distinguishable from the dirt!" << std::endl;
	}
}