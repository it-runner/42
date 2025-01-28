/*
	Allocates (with malloc(3)) and returns an array of strings obtained
	by splitting ’s’ using the character ’c’ as a delimiter. The array
	must end with a NULL pointer.

	It returns the array of new strings resulting from the split or NULL
	if the allocation fails.
*/

#include "libft.h"

static int	count_words(const char *str, char c);
static char	*duplicate_word(const char *str, int start, int end);

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!s || !split)
		return (0);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = duplicate_word(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}

static int	count_words(const char *str, char c)
{
	int	i;
	int	trigger;
	int	counter;

	i = 0;
	trigger = 1;
	counter = 0;
	while (str[i])
	{
		if (str[i] != c && trigger)
		{
			trigger = 0;
			counter++;
		}
		else if (str[i] == c)
			trigger = 1;
		i++;
	}
	return (counter);
}

static char	*duplicate_word(const char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc(end - start + 1);
	while (start < end)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}
