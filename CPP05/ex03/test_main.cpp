#include <iostream>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "test_functions.hpp"
#include "Intern.hpp"

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

	// Testing PresidentialPardonForm
	PresidentialPardonForm presidentialForm("John Doe");
	Bureaucrat Jasmin("Jasmin", 1);
	Jasmin.signForm(presidentialForm);
	Jasmin.executeForm(presidentialForm);

	Bureaucrat Bob("Bob", 50);
	Bob.signForm(presidentialForm);
	Bob.executeForm(presidentialForm);

	// Testing RobotomyRequestForm
	RobotomyRequestForm robotomyForm("Jane Smith");
	Bureaucrat Erica("Erica", 50);
	Erica.signForm(robotomyForm);
	Erica.executeForm(robotomyForm);

	Bureaucrat Alice("Alice", 75);
	Alice.signForm(robotomyForm);
	Alice.executeForm(robotomyForm);

	Bureaucrat Charlie("Charlie", 25);
	Charlie.signForm(robotomyForm);
	Charlie.executeForm(robotomyForm);

	// Testing ShrubberyCreationForm
	ShrubberyCreationForm shrubberyForm("Garden");
	Bureaucrat Dave("Dave", 100);
	Dave.signForm(shrubberyForm);
	Dave.executeForm(shrubberyForm);

	Bureaucrat Eve("Eve", 30);
	Eve.signForm(shrubberyForm);
	Eve.executeForm(shrubberyForm);

	// Testing intern
	Intern intern;
	AForm *form1 = intern.makeForm("presidential pardon", "John Doe");
	AForm *form2 = intern.makeForm("robotomy request", "Jane Smith");
	AForm *form3 = intern.makeForm("shrubbery creation", "Treeeees");

	Bureaucrat internBureaucrat("Intern Bureaucrat", 50);
	internBureaucrat.signForm(*form1);
	internBureaucrat.executeForm(*form1);

	internBureaucrat.signForm(*form2);
	internBureaucrat.executeForm(*form2);

	internBureaucrat.signForm(*form3);
	internBureaucrat.executeForm(*form3);

	delete form1;
	delete form2;
	delete form3;




	return 0;
}