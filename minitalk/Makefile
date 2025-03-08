NAME			= minitalk

LIBFT			= libft/libft.a

CC				= cc
CCFLAGS			= cc -Wall -Werror -Wextra
MAKEFLAGS 		+= -s

SERVER = server
CLIENT = client
SRCS_SERVER = server.c
SRCS_CLIENT = client.c
SRCS_SERVER_BONUS = server_bonus.c
SRCS_CLIENT_BONUS = client_bonus.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER_BONUS = $(SRCS_SERVER_BONUS:.c=.o)
OBJS_CLIENT_BONUS = $(SRCS_CLIENT_BONUS:.c=.o)

${NAME} = all;

all: $(SERVER) $(CLIENT)
		@echo "\033[32m[Server and client created successfully!]\033[0m"

$(SERVER) $(CLIENT): $(OBJS_SERVER) $(OBJS_CLIENT) $(LIBFT)
		${CCFLAGS} ${OBJS_SERVER} libft/libft.a -o ${SERVER}
		${CCFLAGS} ${OBJS_CLIENT} libft/libft.a -o ${CLIENT}

$(LIBFT):
		${MAKE} -C ./libft

bonus: ${OBJS_SERVER_BONUS} ${OBJS_CLIENT_BONUS} ${LIBFT}
		${CCFLAGS} ${OBJS_SERVER_BONUS} libft/libft.a -o ${SERVER}
		${CCFLAGS} ${OBJS_CLIENT_BONUS} libft/libft.a -o ${CLIENT}
			@echo "\033[32m[Bonus created successfully!]\033[0m"

clean:	
		$(MAKE) clean -C ./libft
		rm -rf ${OBJS_SERVER} ${OBJS_CLIENT} ${OBJS_SERVER_BONUS} ${OBJS_CLIENT_BONUS}
			@echo "\033[33m[Cleaned up]\033[0m"

fclean:	clean
		$(MAKE) fclean -C ./libft
		rm -rf $(SERVER) $(CLIENT)
			@echo "\033[33m[Fully cleaned up]\033[0m"

re:			fclean all

rebonus:	fclean bonus