NAME = libftprintf.a

SRCS := $(wildcard ./src/*.c) 

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $@ $^
	@echo "Library $@ created successfully"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I inc

clean:
	@$(RM) $(OBJS)
	@echo "All objects cleaned successfully"

fclean: clean
	@$(RM) $(NAME)
	@echo "All objects and library $(NAME) cleaned successfully"

re: fclean all

.PHONY: all clean fclean re