#include <PresidentialPardonForm.hpp>
#include <Bureaucrat.hpp> // Include the header file for the Bureaucrat class

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	// std::cout << "PresidentialPardonForm constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other.getName(), other.getSignGrade(), other.getExecGrade()), _target(other._target)
{
	// std::cout << "PresidentialPardonForm copy constructor" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	// std::cout << "PresidentialPardonForm destructor" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	(void)other;
	return (*this);
}

std::string PresidentialPardonForm::getTarget() const
{
	return _target;
}


void PresidentialPardonForm::action() const
{
	std::cout << "Hereby we declare that " << _target << " has officially been pardoned by the galactic president, Zafod Beeblebrox." << std::endl;
}