SRCS = main.cpp	\
Bureaucrat.cpp	\
AForm.cpp	\
ShrubberyCreationForm.cpp	\
RobotomyRequestForm.cpp	\
PresidentialPardonForm.cpp	\
Intern.cpp

OBJS = ${SRCS:.cpp=.o}
NAME = Intern
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJS): Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp Intern.hpp

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
