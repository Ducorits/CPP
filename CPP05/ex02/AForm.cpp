#include <AForm.hpp>
#include <Bureaucrat.hpp>
#include <iostream>

AForm::AForm(const std::string n, int sg, int eg) : _name(n), _sign_grade(sg), _exec_grade(eg), _signed(false)
{
	if (this->_sign_grade < 1 || this->_exec_grade < 1)
	{
		throw AForm::GradeTooHighException();
	}
	else if (this->_sign_grade > 150 || this->_exec_grade > 150)
	{
		throw AForm::GradeTooLowException();
	}
	// std::cout << "AForm constructor" << std::endl;
}

AForm::AForm(const AForm &other) : _name(other.getName()), _sign_grade(other.getSignGrade()), _exec_grade(getExecGrade()), _signed(other.getSign())
{
	// std::cout << "AForm copy constructor" << std::endl;
}

AForm::~AForm()
{
	// std::cout << "AForm destructor" << std::endl;
}

std::string AForm::getName(void) const
{
	return (this->_name);
}

int AForm::getSignGrade(void) const
{
	return (this->_sign_grade);
}

int AForm::getExecGrade(void) const
{
	return (this->_exec_grade);
}

bool AForm::getSign(void) const
{
	return (this->_signed);
}

AForm &AForm::operator=(const AForm &other)
{
	(*this)._signed = other.getSign();
	return (*this);
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade Too High!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade Too Low!";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form not signed!";
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_sign_grade)
		this->_signed = true;
	else
		throw AForm::GradeTooLowException();
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->_exec_grade)
		throw AForm::GradeTooLowException();
	if (!this->_signed)
		throw AForm::FormNotSignedException();
	this->executeForm();
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
	os << form.getName() << ":\n - AForm sign grade: " << form.getSignGrade() << "\n - AForm exec grade: " << form.getExecGrade() << "\n - Signature: " << form.getSign();
	return (os);
}
