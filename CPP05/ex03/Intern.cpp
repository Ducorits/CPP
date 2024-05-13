#include <iostream>
#include <string>
#include <Intern.hpp>
#include <RobotomyRequestForm.hpp>
#include <PresidentialPardonForm.hpp>
#include <ShrubberyCreationForm.hpp>
#include <map>
#include <functional>

// Default constructor
Intern::Intern()
{
}

// Copy constructor
Intern::Intern(const Intern& other) {
	*this = other;
}

// Destructor
Intern::~Intern() {}

// Copy assignment operator
Intern& Intern::operator=(const Intern& other) {
	(void)other;
	return *this;
}

AForm* Intern::makeForm(std::string name, std::string target) {
	std::map<std::string, std::function<AForm*(std::string)>> formConstructors = { // Use type alias
		{"robotomy request", [](std::string target) { return new RobotomyRequestForm(target); }},
		{"presidential pardon", [](std::string target) { return new PresidentialPardonForm(target); }},
		{"shrubbery creation", [](std::string target) { return new ShrubberyCreationForm(target); }}
	};

	std::cout << "Intern creates " << name << " form" << std::endl;
	auto it = formConstructors.find(name);
	if (it != formConstructors.end()) {
		return it->second(target);
	} else {
		std::cout << "Invalid form name" << std::endl;
		return nullptr;
	}
}
