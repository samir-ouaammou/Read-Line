/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaammo <souaammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:14:03 by souaammo          #+#    #+#             */
/*   Updated: 2024/11/14 16:10:01 by souaammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	l;

	if (!str)
		return (0);
	l = 0;
	while (str[l])
		l++;
	return (l);
}

static char	*ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static char	*ft_strcat(char *dst, const char *src)
{
	size_t	i;
	size_t	d_len;

	d_len = ft_strlen(dst);
	i = 0;
	while (src[i])
	{
		dst[d_len + i] = src[i];
		i++;
	}
	dst[d_len + i] = '\0';
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined;

	if (!s1 && !s2)
		return (NULL);
	joined = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!joined)
		return (NULL);
	ft_strcpy(joined, s1);
	ft_strcat(joined, s2);
	free(s1);
	return (joined);
}
