/*
	Allocates (with malloc(3)) and returns a copy of ’s1’ with the 
	characters specified in ’set’ removed from the beginning 
	and the end of the string.

	It returns the trimmed string or NULL if the allocation fails.
*/

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;
	char	*new_str;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	len = ft_strlen(s1);
	while (i < len && ft_strchr(set, s1[i]))
		i++;
	while (len > i && ft_strchr(set, s1[len - 1]))
		len--;
	len = len - i;
	new_str = malloc(len + 1);
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s1 + i, len + 1);
	return (new_str);
}
