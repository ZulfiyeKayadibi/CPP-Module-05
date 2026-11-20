#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45), target("Default")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("RobotomyRequestForm", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
	: AForm(src), target(src.target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &nw)
{
	if (this != &nw)
		AForm::operator=(nw);
	return *this;
}

std::string RobotomyRequestForm::getTarget() const
{
	return target;
}

void RobotomyRequestForm::execAction() const
{
	std::cout << "-TRRRRRRRRRRRRRRRRRRR-" << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "The robotomy of " << target << " failed" << std::endl;
}
