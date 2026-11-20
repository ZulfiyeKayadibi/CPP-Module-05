#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>

class AForm;

class Intern
{
	private:
		static AForm *makeShrubbery(const std::string &target);
		static AForm *makeRobotomy(const std::string &target);
		static AForm *makePresidential(const std::string &target);
	public:
		Intern();
		~Intern();
		Intern(const Intern &src);
		Intern & operator=(const Intern &nw);

		AForm *makeForm(const std::string &formName, const std::string &target);
};

#endif
