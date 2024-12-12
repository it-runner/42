/*
	Applies the function ’f’ on each character of the string passed
	as argument, passing its index as first argument. Each character
	is passed by address to ’f’ to be modified if necessary.
	The difference between ft_striteri and ft_strmapi is
	that ft_striteri doesn't return anything and
	works directly on the original string.
*/

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
