/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaammo <souaammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:14:03 by souaammo          #+#    #+#             */
/*   Updated: 2024/11/12 18:16:59 by souaammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchar(const char *str, char c)
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

char	*ft_strdup(const char *str)
{
	size_t	i;
	char	*res;

	res = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	ft_strcpy(res, s1);
	ft_strcat(res, s2);
	return (res);
}
