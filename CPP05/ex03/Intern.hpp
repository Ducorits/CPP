#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"

class Intern {
public:
	Intern();
	Intern(const Intern &other);
	~Intern();

	// TODO: Add member functions here
	AForm *makeForm(std::string form, std::string target);
	Intern &operator=(const Intern &other);

private:
	// TODO: Add member variables here
};

#endif // INTERN_HPP