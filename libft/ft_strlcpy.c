/*
	strlcpy() copies the input string into a destination string.
	If the destination buffer, limited by its size, isn't large enough
	to hold the copy, the resulting string is truncated (but it is guaranteed
	to be null-terminated).
	
	It returns the length of the total string they tried to create.
 */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
