/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.cpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/13 15:18:08 by dritsema      #+#    #+#                 */
/*   Updated: 2024/06/19 14:39:15 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ShrubberyCreationForm.hpp>
#include <fstream>
#include <Bureaucrat.hpp>

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) : AForm(other.getName(), other.getSignGrade(), other.getExecGrade()), _target(other._target)
{

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	(void)other;
	return (*this);
}

std::string ShrubberyCreationForm::getTarget() const
{
	return _target;
}

void ShrubberyCreationForm::executeForm() const
{
	std::ofstream file;
	file.open(_target + "_shrubbery");
	file << "               ,@@@@@@@,              " << std::endl;
	file << "       ,,,.   ,@@@@@@/@@,  .oo8888o.  " << std::endl;
	file << "    ,&%&&%&&%,@@@@@/@@@@@@,8888\\88/8o " << std::endl;
	file << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
	file << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
	file << "   %&&%/ %&&%&&@@\\ V /@@' `88\\8 `/88' " << std::endl;
	file << "   `&%\\ ` /%&'    |.|        \\ '|8'   " << std::endl;
	file << "       |o|        | |         | |     " << std::endl;
	file << "       |.|        | |         | |     " << std::endl;
	file << "    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
	file.close();
}
