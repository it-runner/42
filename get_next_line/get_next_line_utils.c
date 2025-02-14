#include "get_next_line.h"

ssize_t	str_len(const char *s)
{
	ssize_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	create_empty_line(char **str)
{
	*str = malloc(1);
	if (!*str)
		return (0);
	(*str)[0] = '\0';
	return (1);
}

ssize_t	find_newline(char *buf, ssize_t i)
{
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}
