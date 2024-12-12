/*
	The memset() function fills the first n bytes of the memory area
	pointed to by s with the constant byte c.

	The memset() function returns a pointer to the memory area s.
*/

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	size_t			i;
	unsigned char	*s;

	i = 0;
	s = ptr;
	while (i < num)
	{
		s[i] = (unsigned char)value;
		i++;
	}
	return (ptr);
}
