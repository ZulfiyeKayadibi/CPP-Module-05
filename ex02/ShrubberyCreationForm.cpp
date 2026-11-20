#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), target("Default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
	: AForm(src), target(src.target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &nw)
{
	if (this != &nw)
		AForm::operator=(nw);
	return *this;
}

std::string ShrubberyCreationForm::getTarget() const
{
	return target;
}

void ShrubberyCreationForm::execAction() const
{
	std::ofstream file((target + "_shrubbery").c_str());

	if (!file.is_open())
	{
		std::cout << "Error: could not create " << target << "_shrubbery" << std::endl;
		return ;
	}
	file << "        *\n"
		<< "       ***\n"
		<< "      *****\n"
		<< "     *******\n"
		<< "    *********\n"
		<< "       |||\n"
		<< "      *****\n"
		<< "     *******\n"
		<< "    *********\n"
		<< "   ***********\n"
		<< "  *************\n"
		<< " ***************\n"
		<< "       |||\n"
		<< "       |||\n"
		<< "       |||\n\n";
	file.close();
}
