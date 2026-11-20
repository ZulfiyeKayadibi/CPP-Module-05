#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
	: name("Default"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
	: name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	validateGrade(gradeToSign);
	validateGrade(gradeToExecute);
}

Form::Form(const Form &exec)
	: name(exec.name), isSigned(exec.isSigned),
	  gradeToSign(exec.gradeToSign), gradeToExecute(exec.gradeToExecute)
{
}

Form::~Form()
{
}

Form &Form::operator=(const Form &nw)
{
	if (this != &nw)
		this->isSigned = nw.isSigned;
	return *this;
}

std::string Form::getName() const
{
	return name;
}

bool Form::getIsSigned() const
{
	return isSigned;
}

int Form::getGradeToSign() const
{
	return gradeToSign;
}

int Form::getGradeToExecute() const
{
	return gradeToExecute;
}

void Form::validateGrade(int value) const
{
	if (value < 1)
		throw GradeTooHighException();
	if (value > 150)
		throw GradeTooLowException();
}

void Form::beSigned(const Bureaucrat &exec)
{
	if (exec.getGrade() > gradeToSign)
		throw GradeTooLowException();
	isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const Form& mineClass)
{
	os << "Form " << mineClass.getName()
		<< ", signed: " << (mineClass.getIsSigned() ? "yes" : "no")
		<< ", grade to sign " << mineClass.getGradeToSign()
		<< ", grade to execute " << mineClass.getGradeToExecute();
	return os;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}
