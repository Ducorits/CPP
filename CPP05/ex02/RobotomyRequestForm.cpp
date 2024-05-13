#include <RobotomyRequestForm.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Bureaucrat.hpp>


RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{

}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) : AForm(other.getName(), other.getSignGrade(), other.getExecGrade()), _target(other._target)
{

}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
	(void)other;
	return (*this);
}

void RobotomyRequestForm::executeForm() const
{
	std::cout << "Executing RobotomyRequestForm on target: " << _target << std::endl;

	// Initiating the robotomy process
	srand(time(nullptr)); // Initializing the random number generator
	bool success = (rand() % 2) == 0; // 50% chance of success

	// Adding drilling noises
	for (int i = 0; i < 5; i++) {
		if (i == 1)
			std::cout << "*VRRRRRR*" << std::endl;
		else if (i == 2)
			std::cout << "*DING* *DING* *DING*" << std::endl;
		else if (i == 3)
			std::cout << "*VRRRRRR*" << std::endl;
		else if (i == 4)
			std::cout << "*BEEP* *BEEP*" << std::endl;
		else
			std::cout << "*VRRRRRR*" << std::endl;
	}
	std::cout << std::endl;

	if (success) {
		std::cout << "Target successfully robotomized! Take care!" << std::endl;
	} else {
		std::cout << "RobotomyRequestForm failed! " << _target << " has lost quite a bit of cognitive function. Come by again!" << std::endl;
	}
}
