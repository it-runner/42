/*
	strlcpy() — size-bounded string copying.
	Designed to be safer, more consistent, and less error prone replacements
	for strncpy(3).

	It returns the length of the total string it tried to create (the
	length of src. While this may seem somewhat confusing, it was done
	to make truncation detection simple).
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
