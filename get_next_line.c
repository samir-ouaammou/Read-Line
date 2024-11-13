/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaammo <souaammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:12:06 by souaammo          #+#    #+#             */
/*   Updated: 2024/11/13 21:50:50 by souaammo         ###   ########.fr       */
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
	ssize_t	read_byte;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return ((free(line)), NULL);
	read_byte = 1;
	while ((ft_strchr(buffer, '\n') == 0) && (read_byte > 0))
	{
		read_byte = read(fd, buffer, BUFFER_SIZE);
		if (read_byte == -1)
			return ((free(line)), NULL);
		buffer[read_byte] = '\0';
		line = ft_strjoin(line, buffer);
		if (!line)
			return ((free(line)), NULL);
	}
	free(buffer);
	buffer = NULL;
	return (line);
}

char	*ft_read_line(char *buffer)
{
	char	*line;
	size_t	index1;
	size_t	index2;

	if ((!buffer) || (!buffer[0]))
		return (NULL);
	index1 = 0;
	while ((buffer[index1]) && (buffer[index1] != '\n'))
		index1++;
	line = (char *)malloc((index1 + 2) * sizeof(char));
	if (!line)
		return (NULL);
	index2 = 0;
	while (index2 < index1)
	{
		line[index2] = buffer[index2];
		index2++;
	}
	if (buffer[index2] == '\n')
		line[index2++] = '\n';
	line[index2] = '\0';
	return (line);
}

char	*ft_next_line(char *buffer)
{
	char	*next_line;
	size_t	index1;
	size_t	index2;

	if ((!buffer) || (!buffer[0]))
		return (NULL);
	index1 = 0;
	while ((buffer[index1]) && (buffer[index1] != '\n'))
		index1++;
	if (buffer[index1] == '\n')
		index1++;
	next_line = (char *)malloc(((ft_strlen(buffer) - index1) + 1));
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

	if ((fd < 0) || (BUFFER_SIZE <= 0) || (read(fd, 0, 0) <= 0))
		return (NULL);
	next_line = ft_read_buffer_size(fd, next_line);
	line = ft_read_line(next_line);
	next_line = ft_next_line(next_line);
	return (line);
}
