/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaammo <souaammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:12:06 by souaammo          #+#    #+#             */
/*   Updated: 2024/11/14 18:12:07 by souaammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_buffer_size(int fd, char *save)
{
	char	tmp[BUFFER_SIZE + 1];
	int		len;

	while ((!ft_strchr(save, '\n')))
	{
		len = read(fd, tmp, BUFFER_SIZE);
		if (len == 0)
			break ;
		if (len < 0)
			return (NULL);
		tmp[len] = '\0';
		save = ft_strjoin(save, tmp);
		if (!save)
			return (NULL);
	}
	return (save);
}

char	*ft_read_line(char **save)
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
		return (NULL);
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

char	*ft_next_line(char **tmp)
{
	char	*save;
	int		i;
	int		j;

	if ((!(*tmp)) || (!(*tmp)[0]))
		return ((free(*tmp)), (*tmp = NULL), (NULL));
	i = 0;
	while (((*tmp)[i]) && ((*tmp)[i] != '\n'))
		i++;
	if ((*tmp)[i] == '\n')
		i++;
	save = malloc((ft_strlen((*tmp)) - i) + 1);
	if (!save)
		return (free(save), NULL);
	j = 0;
	while ((*tmp)[i])
	{
		save[j] = (*tmp)[i + j];
		j++;
	}
	save[j] = '\0';
	free((*tmp));
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if ((fd < 0) || (BUFFER_SIZE <= 0) || (read(fd, 0, 0) < 0))
		return (NULL);
	save = ft_read_buffer_size(fd, save);
	if (!save)
		return (NULL);
	line = ft_read_line(&save);
	if (!line)
		return (NULL);
	save = ft_next_line(&save);
	if (!save[0])
	{
		free(save);
		save = NULL;
	}
	return (line);
}
