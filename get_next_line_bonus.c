/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaammo <souaammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:12:06 by souaammo          #+#    #+#             */
/*   Updated: 2024/11/20 14:30:15 by souaammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_buffer_size(int fd, char *save)
{
	char	*buffer;
	char	*temp;
	ssize_t	len;

	buffer = (char *)malloc((BUFFER_SIZE * sizeof(char)) + 1);
	if (!buffer)
		return (free(save), NULL);
	while (!ft_strchr(save, '\n'))
	{
		len = read(fd, buffer, BUFFER_SIZE);
		if (len <= 0)
			break ;
		buffer[len] = '\0';
		temp = ft_strjoin(save, buffer);
		if (!temp)
			return (free(buffer), free(save), NULL);
		save = temp;
	}
	return (free(buffer), save);
}

char	*read_line(char *save)
{
	char	*line;
	int		i;

	if ((!save) || (!save[0]))
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while ((save[i]) && (save[i] != '\n'))
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
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
	static char	*save[1024];
	char		*line;

	if (fd < 0 || fd > 1024)
		return (NULL);
	if (BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (free(save[fd]), save[fd] = NULL, NULL);
	save[fd] = read_buffer_size(fd, save[fd]);
	if (!save[fd])
		return (NULL);
	line = read_line(save[fd]);
	if (!line)
		return (free(save[fd]), save[fd] = NULL, NULL);
	save[fd] = next_line(&save[fd]);
	if (save[fd] && !save[fd][0])
		return (free(save[fd]), save[fd] = NULL, line);
	return (line);
}
