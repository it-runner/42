/*
	The strlen() function calculates and returns the length of the string
	pointed to by s, excluding the terminating null byte ('\0').
*/

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}
