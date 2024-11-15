/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaammo <souaammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:12:06 by souaammo          #+#    #+#             */
/*   Updated: 2024/11/15 12:20:41 by souaammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_buffer_size(int fd, char *save)
{
	char	*buffer;
	char	*temp;
	ssize_t	bytes_read;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (free(save), save = NULL, NULL);
	while (!ft_strchr(save, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(save, buffer);
		if (!temp)
			return (free(buffer), buffer = NULL, free(save), save = NULL, NULL);
		save = temp;
	}
	return (free(buffer), buffer = NULL, save);
}

char	*read_line(char **save)
{
	char	*line;
	int		i;

	if ((!(*save)) || (!(*save)[0]))
		return ((free(*save)), (*save = NULL), (NULL));
	i = 0;
	while (((*save)[i]) && ((*save)[i] != '\n'))
		i++;
	if ((*save)[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (free(*save), *save = NULL, NULL);
	i = 0;
	while (((*save)[i]) && ((*save)[i] != '\n'))
	{
		line[i] = (*save)[i];
		i++;
	}
	if ((*save)[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*next_line(char **tmp)
{
	char	*save;
	int		i;
	int		j;

	if (!*tmp || !(*tmp)[0])
		return (free(*tmp), *tmp = NULL, NULL);
	i = 0;
	while ((*tmp)[i] && (*tmp)[i] != '\n')
		i++;
	if ((*tmp)[i] == '\n')
		i++;
	save = malloc(ft_strlen(*tmp) - i + 1);
	if (!save)
		return (free(*tmp), *tmp = NULL, NULL);
	j = 0;
	while ((*tmp)[i + j])
	{
		save[j] = (*tmp)[i + j];
		j++;
	}
	save[j] = '\0';
	free(*tmp);
	*tmp = NULL;
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (free(save), save = NULL, NULL);
	save = read_buffer_size(fd, save);
	if (!save)
		return (NULL);
	line = read_line(&save);
	if (!line)
		return (free(save), save = NULL, NULL);
	save = next_line(&save);
	if (save && !save[0])
		return (free(save), save = NULL, line);
	return (line);
}
