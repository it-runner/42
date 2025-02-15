/*
	The strrchr() function returns a pointer to the last occurrence
	of the character c in the string s. 
*/

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char		*last_occ;
	size_t			i;
	unsigned char	uc;

	last_occ = NULL;
	i = 0;
	uc = (unsigned char)c;
	while (str[i])
	{
		if (str[i] == uc)
			last_occ = &str[i];
		i++;
	}
	if (str[i] == uc)
		last_occ = &str[i];
	return ((char *)last_occ);
}
