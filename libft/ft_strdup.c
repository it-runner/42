/*
	The strdup() function returns a pointer to a new string which is
	a duplicate of the string s. Memory for the new string is obtained with
	malloc(3), and can be freed with free(3).
*/

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	int		len;
	int		n;

	len = ft_strlen(s);
	n = 0;
	ptr = malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	while (s[n])
	{
		ptr[n] = s[n];
		n++;
	}
	ptr[n] = '\0';
	return (ptr);
}
