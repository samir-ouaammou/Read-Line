/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaammo <souaammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:12:06 by souaammo          #+#    #+#             */
/*   Updated: 2024/11/14 16:10:04 by souaammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(const char *str, char c)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_read_buffer_size(int fd, char *line)
{
	char	*buffer;
	int		read_byte;

	buffer = NULL;
	read_byte = 1337;
	while ((ft_strchr(buffer, '\n')) && (read_byte > 0))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
		read_byte = read(fd, buffer, BUFFER_SIZE);
		buffer[read_byte] = '\0';
		line = ft_strjoin(line, buffer);
		if (!line)
			return (free(buffer), NULL);
		read_byte = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (line);
}

char	*ft_read_line(char *buffer)
{
	char	*line;
	int		index;

	if ((!buffer) || (!buffer[0]))
		return (NULL);
	index = 0;
	while ((buffer[index]) && (buffer[index] != '\n'))
		index++;
	if (buffer[index] == '\n')
		index++;
	line = malloc(index + 1);
	if (!line)
		return (NULL);
	index = 0;
	while ((buffer[index]) && (buffer[index] != '\n'))
	{
		line[index] = buffer[index];
		index++;
	}
	if (buffer[index] == '\n')
		line[index++] = '\n';
	line[index] = '\0';
	return (line);
}

char	*ft_next_line(char *buffer)
{
	char	*next_line;
	int		index1;
	int		index2;

	if ((!buffer) || (!buffer[0]))
		return (NULL);
	index1 = 0;
	while ((buffer[index1]) && (buffer[index1] != '\n'))
		index1++;
	if (buffer[index1] == '\n')
		index1++;
	next_line = malloc((ft_strlen(buffer) - index1) + 1);
	if (!next_line)
		return (NULL);
	index2 = 0;
	while (buffer[index1])
	{
		next_line[index2] = buffer[index1 + index2];
		index2++;
	}
	next_line[index2] = '\0';
	free(buffer);
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char	*next_line;
	char		*line;

	if ((fd < 0) || (BUFFER_SIZE <= 0) || (read(fd, 0, 0) < 0))
		return (NULL);
	next_line = ft_read_buffer_size(fd, next_line);
	if (!next_line)
		return (NULL);
	line = ft_read_line(next_line);
	next_line = ft_next_line(next_line);
	return (line);
}
