/*
	The bzero() function erases the data in the n bytes of the memory 
	starting at the location pointed to by s, by writing zeros 
	(bytes containing '\0') to that area.
*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	if (n > 0)
		ft_memset(s, 0, n);
}
