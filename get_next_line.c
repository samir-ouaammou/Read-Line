/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaammo <souaammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:12:06 by souaammo          #+#    #+#             */
/*   Updated: 2024/11/13 10:04:10 by souaammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	l;

	l = 0;
	while (str[l])
		l++;
	return (l);
}

static char	*ft_read_size(int fd, char *line)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	read_byte;

	read_byte = 1;
	while ((ft_strchar(line, '\n') == 0) && read_byte > 0)
	{
		read_byte = read(fd, buffer, BUFFER_SIZE);
		if (read_byte == -1)
			return (NULL);
		buffer[read_byte] = '\0';
		line = ft_strjoin(line, buffer);
		if (!line)
			return (NULL);
	}
	if (read_byte == -1)
		return (NULL);
	return (line);
}

static char	*ft_read_line(char *str)
{
	char	*line;
	size_t	index;
	size_t	temp;

	index = 0;
	temp = 1;
	while ((str[index]) && (str[index != '\n']))
		index++;
	if (str[index] == '\n')
		temp = 2;
	line = (char *)malloc((index + temp) * sizeof(char));
	if (!line)
		return (NULL);
	index = 0;
	while ((str[index]) && (str[index] != '\n'))
	{
		line[index] = str[index];
		index++;
	}
	if (temp == 2)
		line[index++] = '\n';
	line[index] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*next_line;
	char		*line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= 2147483647 || read(fd, 0,
			0) == -1)
		return (NULL);
	temp = ft_read_size(fd, next_line);
	if (!temp)
		return (NULL);
	line = ft_read_line(temp);
	if (temp[ft_strlen(line)] != '\0')
		next_line = &temp[ft_strlen(line) + 1];
	free(temp);
	return (line);
}
