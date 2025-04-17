/* auxiliary function for ft_handle_input */
static void	ft_write_all(int fd, const char *buf, size_t length)
{
	ssize_t	bytes_written;
	size_t	total;

	total = 0;
	while (total < length)
	{
		bytes_written = write(fd, buf + total, length - total);
		if (bytes_written <= 0)
			break ;
		total += bytes_written;
	}
}

/* auxiliary function for ft_run_minishell_history */
static int	ft_handle_input(char *history_file, int hist_fd, int *running)
{
	char	*line;

	line = readline("minishell> ");
	if (!line)
	{
		printf("exit\n");
		*running = 0;
		return (1);
	}
	if (!ft_is_str_whitespace(line) && ft_strcmp(line, "exit") != 0)
	{
		add_history(line);
		ft_write_all(hist_fd, line, ft_strlen(line));
		ft_write_all(hist_fd, "\n", 1);
	}
	ft_process_command(line, history_file, running);
	free(line);
	return (0);
}

/* main history function */
int	ft_run_minishell_history(void)
{
	char	*history_file;
	int		hist_fd;
	int		running;

	if (ft_init_minishell_history(&history_file))
		return (1);
	hist_fd = open(history_file, O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (hist_fd == -1)
		return (1);
	running = 1;
	while (running)
	{
		if (ft_handle_input(history_file, hist_fd, &running))
			break ;
	}
	close(hist_fd);
	ft_finalize_history(history_file);
	return (0);
}
