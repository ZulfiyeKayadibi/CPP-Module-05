SRCS = main.cpp	\
Bureaucrat.cpp	\
Form.cpp

OBJS = ${SRCS:.cpp=.o}
NAME = Form
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJS): Bureaucrat.hpp Form.hpp

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
