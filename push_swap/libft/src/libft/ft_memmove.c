/*
	The  memmove() function copies n bytes from memory area src
	to memory area dest. The memory areas may overlap: copying takes place
	as though the bytes in src are first copied into a temporary array
	that does not overlap src or dest, and the bytes are then copied
	from the temporary array to dest.

	The memmove() function returns a pointer to dest.
*/

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest || !src)
		return (NULL);
	if (dest == src || n == 0)
		return (dest);
	i = 0;
	if (dest > src)
	{
		while (n)
		{
			((unsigned char *)dest)[n - 1] = ((unsigned char *)src)[n - 1];
			n--;
		}
	}
	else
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}
