#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>
#include <stdexcept>

Bureaucrat *createBureaucrat(const std::string name, int grade)
{
	try
	{
		Bureaucrat *crat = new Bureaucrat(name, grade);
		std::cout << *crat << std::endl;
		return (crat);
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception! " << e.what() << std::endl;
		return NULL;
	}
}

void trySignForm(Bureaucrat &crat, Form &form)
{
	try
	{
		crat.signForm(form);
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception! " << e.what() << std::endl;
	}
}

void tryPromote(Bureaucrat &bureaucrat)
{
	try
	{
		bureaucrat.promote();
	}
	catch (const std::exception &e)
	{
		std::cout << bureaucrat.getName() << " Could not be promoted. He's already the max grade!" << std::endl;
	}
}

void tryDemote(Bureaucrat &bureaucrat)
{
	try
	{
		bureaucrat.demote();
	}
	catch (const std::exception &e)
	{
		std::cout << bureaucrat.getName() << " Could not be demoted. Any lower and they won't be distinguishable from the dirt!" << std::endl;
	}
}

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		Bureaucrat *crat1;
		crat1 = createBureaucrat(argv[1], std::atoi(argv[2]));
		std::cout << *crat1 << " Custom Bureaucrat" << std::endl;
	}
	else if (argc > 1)
		std::cout << "Wrong amount of optional arguments. Usage: " << argv[0] << " [NAME] [GRADE]" << std::endl;

	Bureaucrat harry("Harry", 4);
	for (int i = 0; i < 5; i++)
	{
		tryPromote(harry);
		std::cout << harry << std::endl;
	}
	Bureaucrat larry("Larry", 147);
	for (int i = 0; i < 5; i++)
	{
		tryDemote(larry);
		std::cout << larry << std::endl;
	}
	harry = larry;
	Form the_form("Mighty Form", 50, 40);
}
