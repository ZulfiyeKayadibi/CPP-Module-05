#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat zulfiye("Zulfiye", 1);
	Bureaucrat emma("emma", 150);

	std::cout << "\n" << std::endl;

	ShrubberyCreationForm shrub("noel");
	std::cout << shrub << std::endl;
	zulfiye.executeForm(shrub);
	zulfiye.signForm(shrub);
	zulfiye.executeForm(shrub);
	std::cout << shrub << std::endl;

	std::cout << "\n" << std::endl;
	
	RobotomyRequestForm robot("WALL.E");
	emma.signForm(robot);
	zulfiye.signForm(robot);
	emma.executeForm(robot);
	zulfiye.executeForm(robot);

	std::cout << "\n" << std::endl;

	PresidentialPardonForm pardon("It");
	zulfiye.signForm(pardon);
	zulfiye.executeForm(pardon);

	return 0;
}
