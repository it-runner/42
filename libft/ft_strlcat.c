/*
	strlcat() — size-bounded string concatenation.
	Designed to be safer, more consistent, and less error prone replacements
	for strncat(3).

	It returns the length of the total string it tried to create (the
	initial length of dst plus the length of src. While this may seem
	somewhat confusing, it was done to make truncation detection simple).

	if strlcat() traverses size characters without finding a NUL,
	the length of the string is considered to be size and the 
	destination string will not be NUL-terminated
	(since there was no space for the NUL).
 */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;
	size_t	dest_len;
	size_t	total_len;

	if ((!dst || !src) && size == 0)
		return (0);
	src_len = ft_strlen(src);
	dest_len = ft_strlen(dst);
	if (dest_len < size)
		total_len = dest_len + src_len;
	else
		return (size + src_len);
	i = 0;
	while (src[i] && (dest_len + i + 1) < size)
	{
		dst[dest_len + i] = src[i];
		i++;
	}
	dst[dest_len + i] = '\0';
	return (total_len);
}
