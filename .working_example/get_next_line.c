#include "get_next_line.h"

static char	*extract_line(char *input)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	if (input[i] == '\0')
		return (0);
	while (input[i] != '\0' && input[i] != '\n')
		i++;
	if (input[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (0);
	i = 0;
	j = 0;
	while (input[i] != '\0' && input[i] != '\n')
		line[j++] = input[i++];
	if (input[i] == '\n')
		line[j++] = input[i++];
	line[j] = '\0';
	return (line);
}

static char	*new_input(char *input)
{
	int		i;
	int		j;
	char	*new_input;

	i = 0;
	while (input[i] != '\0' && input[i] != '\n')
		i++;
	if (input[i] == '\0')
	{
		free(input);
		return (0);
	}
	new_input = malloc(sizeof(char) * (ft_strlen(input) - i + 1));
	if (!new_input)
		return (0);
	i++;
	j = 0;
	while (input[i] != '\0')
		new_input[j++] = input[i++];
	new_input[j] = '\0';
	free(input);
	return (new_input);
}

static char	*get_input(char *input, int fd, char *buffer)
{
	int		bytes_read;
	char	*temp;

	bytes_read = 1;
	while (!ft_strchr(input, '\n') && bytes_read)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(input);
			free(buffer);
			return (0);
		}
		buffer[bytes_read] = '\0';
		if (!input)
			input = ft_strdup("");
		temp = input;
		input = ft_strjoin(temp, buffer);
		free(temp);
	}
	free(buffer);
	return (input);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*input;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	input = get_input(input, fd, buffer);
	if (!input)
		return (0);
	line = extract_line(input);
	input = new_input(input);
	return (line);
}
