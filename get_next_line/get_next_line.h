#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

ssize_t	str_len(const char *s);
int		create_empty_line(char **str);
ssize_t	find_newline(char *buf, ssize_t i);
char	*get_next_line(int fd);

#endif