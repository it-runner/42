#include "minitalk.h"

static void	signal_action(int pid, char *str)
{
	int	i;
	int	c;

	i = 0;
	while (*str)
	{
		c = *str;
		while (i < 8)
		{
			if (c << i & 0b10000000)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			i++;
			usleep(10);
		}
		str++;
		i = 0;
	}
}

static int	validate_arguments(int argc, char **argv)
{
	int	i;

	if (argc != 3 || !argv[2])
	{
		ft_printf("You must provide 2 arguments.\n");
		ft_printf("Format: [./client <SERVER ID (PID)> <STRING>]\n");
		return (1);
	}
	i = 0;
	while (argv[1][i])
	{
		if (!ft_isdigit(argv[1][i]))
		{
			ft_printf("Invalid PID.\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (validate_arguments(argc, argv))
		exit(1);
	signal_action(ft_atoi(argv[1]), argv[2]);
	return (0);
}
