/* error by reading from history file */
int	ft_history_error(int fd)
{
	perror("minishell: history");
	close(fd);
	return (1);
}

// auxiliary function for ft_process_buffer
void	ft_shift_buffer(char *buf, int pos, int *len)
{
	int	j;

	j = pos + 1;
	while (j < *len)
	{
		buf[j - pos - 1] = buf[j];
		j++;
	}
	*len -= pos + 1;
}

/* auxiliary function for ft_display_history */
void	ft_process_buffer(char *buf, int *len, int *ln)
{
	int	i;

	i = 0;
	while (i < *len)
	{
		if (buf[i] == '\n' || buf[i] == '\0')
		{
			buf[i] = '\0';
			if (!(*ln) && !buf[0])
			{
				buf[i++] = '\n';
				continue ;
			}
			printf("%5d  %s\n", ++(*ln), buf);
			buf[i] = '\n';
			ft_shift_buffer(buf, i, len);
			i = 0;
		}
		else
			i++;
	}
}

/* display command history */
void	ft_display_history(const char *history_file)
{
	int		fd;
	int		bytes_read;
	int		line_number;
	char	buffer[BUFFER_SIZE + 1];

	fd = open(history_file, O_RDONLY);
	if (fd == -1)
	{
		printf("No history\n");
		return ;
	}
	bytes_read = 0;
	line_number = 0;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		ft_process_buffer(buffer, &bytes_read, &line_number);
	}
	if (!bytes_read && line_number)
		printf("%5d  %s\n", ++line_number, buffer);
	close(fd);
}
