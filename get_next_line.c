/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaammo <souaammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:12:06 by souaammo          #+#    #+#             */
/*   Updated: 2024/11/12 18:55:28 by souaammo         ###   ########.fr       */
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

static void	*ft_free(char *temp)
{
	free(temp);
	return (NULL);
}

static char	*ft_read_size(int fd, char *line)
{
	char	*temp;
	ssize_t	read_byte;

	temp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	read_byte = 1;
	while ((ft_strchar(line, '\n') == 0) && read_byte > 0)
	{
		read_byte = read(fd, temp, BUFFER_SIZE);
		if (read_byte == -1)
			return (ft_free(line));
		temp[read_byte] = '\0';
		line = ft_strjoin(line, temp);
		if (!line)
			return (temp);
	}
	if (read_byte == -1)
		return (ft_free(temp));
	free(temp);
	return (line);
}

static char	*ft_read_line(char *str)
{
	char	*line;
	size_t	index1;

	index1 = 0;
	while ((str[index1]) && (str[index1 != '\n']))
		index1++;
	line = (char *)malloc((index1 + 1) * sizeof(char));
	if (!line)
		return (NULL);
	index1 = 0;
	while ((str[index1]) && (str[index1] != '\n'))
	{
		line[index1] = str[index1];
		index1++;
	}
	line[index1] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*next_line;
	char		*line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= 2147483647 || read(fd, 0, 0))
		return (NULL);
	temp = ft_read_size(fd, next_line);
	if (!temp)
		return (NULL);
	line = ft_read_line(temp);
	if (temp[ft_strlen(line)] != '\0')
		next_line = &temp[ft_strlen(line) + 1];
	return (line);
}
