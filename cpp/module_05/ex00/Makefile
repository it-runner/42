# Program name
NAME					= Bureaucrat

# Compiler and flags
CXX						= c++
CXXFLAGS				= -Wall -Wextra -Werror -std=c++98
MAKEFLAGS 				+= -s

# Source files
SRCS					= Bureaucrat.cpp main.cpp

# Object files
OBJS					= $(SRCS:.cpp=.o)

# Remove
RM						= rm -f

# Default target
all: $(NAME)
	@echo "Program ready to use."

# Link object files into executable
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^
# $(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

# Compile .cpp files into .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean: remove object files
clean:
	$(RM) $(OBJS)
	@echo "Object files removed."

fclean: clean
	$(RM) $(NAME)
	@echo "Fully cleaned up."

# Rebuild everything
re: fclean all

# Avoid conflicts with files named 'clean' or 'all'
.PHONY: all clean fclean re

ifdef DEBUG
	CXXFLAGS += -g -fsanitize=address
endif

debug:
	$(CXX) -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address  -o $(NAME) $(SRCS)
	@echo "Program ready to use (debug mode)"
