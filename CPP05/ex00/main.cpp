#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>
#include <stdexcept>

int	main(int argc, char **argv)
{
	try {
		Bureaucrat harry("Harry", -10);
		std::cout << harry << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException& e) {
		std::cout << "Exception! " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e) {
		std::cout << "Exception! " << e.what() << std::endl;
	}
	try {
		Bureaucrat harry("Harry", 200);
		std::cout << harry << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException& e) {
		std::cout << "Exception! " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e) {
		std::cout << "Exception! " << e.what() << std::endl;
	}
	if (argc == 3)
	{
		try {
			Bureaucrat crat1(argv[1], std::atoi(argv[2]));
			std::cout << crat1 << " Custom Bureaucrat" << std::endl;
		}
		catch (const Bureaucrat::GradeTooHighException& e) {
			std::cout << "Exception! " << e.what() << std::endl;
		}
		catch (const Bureaucrat::GradeTooLowException& e) {
			std::cout << "Exception! " << e.what() << std::endl;
		}
	}
	else if (argc > 1)
		std::cout << "Wrong amount of optional arguments. Need 2" << std::endl;
	try {
		Bureaucrat harry("Harry", 5);

		for (int i = 0; i < 150; i++)
		{
			harry.promote();
			std::cout << harry << std::endl;
		}
	}
	catch (const Bureaucrat::GradeTooHighException& e) {
		std::cout << "Harry was promoted too many times! " << e.what() << std::endl;
	}
	try {
		Bureaucrat harry("Harry", 145);

		for (int i = 0; i < 150; i++)
		{
			harry.demote();
			std::cout << harry << std::endl;
		}
	}
	catch (const Bureaucrat::GradeTooLowException& e) {
		std::cout << "Harry was demoted too many times! " << e.what() << std::endl;
	}
}
