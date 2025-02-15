/*
	Outputs the character ’c’ to the given file descriptor.
	fd(file descriptor) values;
		0:	Standard input
		1:	Standard output
		2:	Standard error
*/

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd >= 0)
		write(fd, &c, 1);
}
