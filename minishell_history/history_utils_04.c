/* history initialization */
int	ft_init_minishell_history(char **history_file)
{
	*history_file = ft_init_history();
	if (!(*history_file))
	{
		ft_putstr_fd("Warning: History initialization failed\n", STDERR_FILENO);
		return (1);
	}
	return (0);
}

/* parse history commands */
void	ft_process_command(char *line, char *history_file, int *running)
{
	if (ft_strcmp(line, "history") == 0)
		ft_display_history(history_file);
	else if (ft_strcmp(line, "history -c") == 0)
		ft_clear_history_cmd(history_file);
	else if (ft_strcmp(line, "history -s") == 0)
		ft_save_history(history_file);
	else if (ft_strcmp(line, "exit") == 0)
		*running = 0;
	else
		printf("Command not found: %s\n", line);
}

/* finishing work with history file */
void	ft_finalize_history(char *history_file)
{
	ft_save_history(history_file);
	if (history_file)
		free(history_file);
}
