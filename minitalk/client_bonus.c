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
			{
				if (kill(pid, SIGUSR1) == -1)
					ft_printf("Unable to send SIGUSR1\n");
			}
			else
			{
				if (kill(pid, SIGUSR2) == -1)
					ft_printf("Unable to send SIGUSR2\n");
			}
			i++;
			usleep(10);
		}
		str++;
		i = 0;
	}
}

static void	handler(int sig)
{
	static int	message_printed = 0;

	if (!message_printed)
	{
		if (sig == SIGUSR1)
		{
			ft_printf("The signal was received successfully.\n");
			message_printed = 1;
		}
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
	struct sigaction	sa;
	int					i;

	if (validate_arguments(argc, argv))
		exit(1);
	sa.sa_handler = &handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_putstr_fd("sigaction (SIGUSR1)", 2);
		exit(1);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_putstr_fd("sigaction (SIGUSR2)", 2);
		exit(1);
	}
	signal_action(ft_atoi(argv[1]), argv[2]);
	return (0);
}
