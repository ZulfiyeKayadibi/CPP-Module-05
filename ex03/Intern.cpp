#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &src)
{
	(void)src;
}

Intern::~Intern()
{
}

Intern &Intern::operator=(const Intern &nw)
{
	(void)nw;
	return *this;
}

AForm *Intern::makeShrubbery(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makeRobotomy(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::makePresidential(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
	const std::string names[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	AForm *(*builders[3])(const std::string &) = {
		&Intern::makeShrubbery,
		&Intern::makeRobotomy,
		&Intern::makePresidential
	};

	for (int i = 0; i < 3; ++i)
	{
		if (names[i] == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return builders[i](target);
		}
	}
	std::cout << "Error: Intern cannot create " << formName
		<< ": no such form" << std::endl;
	return NULL;
}
