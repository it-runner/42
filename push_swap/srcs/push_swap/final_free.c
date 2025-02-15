#include "../../inc/push_swap.h"

void	final_free(int argc, char **argv)
{
	size_t	i;

	i = 0;
	if (argc == 2)
	{
		while (argv[i])
			free(argv[i++]);
		free(argv);
	}
}
