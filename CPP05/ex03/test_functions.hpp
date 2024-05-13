#include <Bureaucrat.hpp>
#include <AForm.hpp>


Bureaucrat *createBureaucrat(const std::string name, int grade);
void trySignForm(Bureaucrat &crat, AForm &form);
void tryPromote(Bureaucrat &bureaucrat);
void tryDemote(Bureaucrat &bureaucrat);