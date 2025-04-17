/* creates a path to the history file in home directory */
char	*ft_create_history_path(void)
{
	char	*home_dir;
	char	*history_file;

	home_dir = getenv("HOME");
	if (!home_dir)
	{
		ft_putstr_fd("minishell: history: could not get HOME directory\n",
			STDERR_FILENO);
		return (NULL);
	}
	history_file = ft_strjoin(home_dir, "/.minishell_history");
	if (!history_file)
	{
		ft_putstr_fd("minishell: history: unable to create history file\n",
			STDERR_FILENO);
		return (NULL);
	}
	return (history_file);
}

/* check if the full string is white space */
int	ft_is_str_whitespace(const char *str)
{
	size_t	i;

	if (!str)
		return (1);
	i = 0;
	while (str[i])
	{
		if (!ft_isspace(str[i]))
			return (0);
		i++;
	}
	return (1);
}

// auxiliary function to process buffer and add lines to history
void	ft_process_history_buffer(char *buffer)
{
	char	*line;
	char	*newline;

	line = buffer;
	newline = ft_strchr(line, '\n');
	while (newline)
	{
		*newline = '\0';
		if (ft_strlen(line) > 0 && ft_strcmp(line, "exit") != 0
			&& !ft_is_str_whitespace(line))
			add_history(line);
		line = newline + 1;
		newline = ft_strchr(line, '\n');
	}
	if (ft_strlen(line) > 0 && ft_strcmp(line, "exit") != 0
		&& !ft_is_str_whitespace(line))
		add_history(line);
}

/* check access to file */
int	ft_check_history_access(char *history_file)
{
	if (access(history_file, F_OK) == -1)
		return (0);
	if (access(history_file, R_OK) == -1)
	{
		ft_putstr_fd("minishell: history: no read permission for ",
			STDERR_FILENO);
		ft_putendl_fd(history_file, STDERR_FILENO);
		return (-1);
	}
	return (0);
}

/* read history file */
int	ft_read_history_file(int fd)
{
	char	buffer[BUFFER_SIZE];
	ssize_t	bytes_read;

	bytes_read = read(fd, buffer, sizeof(buffer) - 1);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		ft_process_history_buffer(buffer);
		bytes_read = read(fd, buffer, sizeof(buffer) - 1);
	}
	if (bytes_read == -1)
		return (ft_history_error(fd));
	close(fd);
	return (0);
}
