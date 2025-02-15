/* 
	strnstr() locates a substring (needle) in a string (haystack).
*/

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!needle[0])
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while (needle[j] == haystack[i + j] && (i + j) < len)
		{
			if (!(needle[j + 1]))
				return ((char *)&haystack[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
