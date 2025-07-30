# Program name
NAME					= Intern

# Compiler and flags
CXX						= c++
CXXFLAGS				= -Wall -Wextra -Werror -std=c++98
MAKEFLAGS 				+= -s

# Source files
SRCS					= Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp \
						  ShrubberyCreationForm.cpp Intern.cpp main.cpp

# Object files
OBJS					= $(SRCS:.cpp=.o)

# Shrubbery files to clean
SHRUBBERY_FILES			= *_shrubbery

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
	$(RM) $(SHRUBBERY_FILES)
	@echo "Object files removed."

fclean: clean
	$(RM) $(NAME)
	@echo "Fully cleaned up."

# Rebuild everything
re: fclean all

# Avoid conflicts with files named 'clean' or 'all'
.PHONY: all clean fclean re debug

ifdef DEBUG
	CXXFLAGS += -g -fsanitize=address
endif

debug:
	$(CXX) -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address  -o $(NAME) $(SRCS)
	@echo "Program ready to use (debug mode)"
