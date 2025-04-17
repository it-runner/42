/* main function that loads history */
int	ft_load_history(char *history_file)
{
	int	fd;
	int	access_result;

	if (access(history_file, F_OK) == -1)
		return (0);
	fd = open(history_file, O_RDONLY);
	if (fd == -1)
		return (ft_history_error(-1));
	access_result = ft_check_history_access(history_file);
	if (access_result != 0)
	{
		close(fd);
		return (access_result);
	}
	return (ft_read_history_file(fd));
}

/* main function of history initialization */
char	*ft_init_history(void)
{
	char	*history_file;
	int		fd;

	history_file = ft_create_history_path();
	if (!history_file)
		return (NULL);
	fd = open(history_file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
	{
		free(history_file);
		return (NULL);
	}
	close(fd);
	if (ft_load_history(history_file) != 0)
		ft_putstr_fd("minishell: history: failed to load history\n",
			STDERR_FILENO);
	return (history_file);
}

/* auxiliary function for ft_save_history */
static int	ft_save_entries_to_history(int fd, HIST_ENTRY **entries)
{
	int	i;

	i = 0;
	while (entries && entries[i])
	{
		if (ft_strncmp(entries[i]->line, "exit", 4) == 0
			&& (entries[i]->line[4] == ' ' || entries[i]->line[4] == '\0'
				|| ft_is_str_whitespace(entries[i]->line)))
		{
			i++;
			continue ;
		}
		write(fd, entries[i]->line, ft_strlen(entries[i]->line));
		write(fd, "\n", 1);
		i++;
	}
	return (0);
}

/* write history to file */
int	ft_save_history(char *history_file)
{
	int			fd;
	HIST_ENTRY	**entries;

	fd = open(history_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("minishell: history");
		return (1);
	}
	entries = history_list();
	ft_save_entries_to_history(fd, entries);
	close(fd);
	return (0);
}

/* clear command history */
int	ft_clear_history_cmd(char *history_file)
{
	int	fd;

	if (access(history_file, F_OK) == 0 && access(history_file, W_OK) != 0)
	{
		ft_putstr_fd("minishell: history: no write permission for ",
			STDERR_FILENO);
		write(STDERR_FILENO, history_file, ft_strlen(history_file));
		write(STDERR_FILENO, "\n", 1);
		return (-1);
	}
	fd = open(history_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("minishell: history");
		return (-1);
	}
	close(fd);
	rl_clear_history();
	return (0);
}
