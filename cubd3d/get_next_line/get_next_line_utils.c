/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:39:36 by redarnet          #+#    #+#             */
/*   Updated: 2020/01/06 15:47:58 by redarnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	if (str)
		while (str[i] != '\0')
			i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	y;
	size_t	x;

	y = 0;
	x = 0;
	if (!s1 && !s2)
		return (NULL);
	if ((str = malloc(sizeof(char) * ft_strlen(s1)
			+ ft_strlen(s2) + 1)) == NULL)
		return (0);
	if (s1)
		while (s1[x] != '\0')
		{
			str[x] = s1[x];
			x++;
		}
	if (s2)
		while (s2[y] != '\0')
		{
			str[x + y] = s2[y];
			y++;
		}
	str[x + y] = '\0';
	return (str);
}

int		ft_taille_malloc(size_t i, size_t start, size_t len)
{
	size_t x;

	if (i - start > len)
		x = len;
	else
		x = i - start;
	return (x);
}

char	*ft_substr(char *s, size_t start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	x;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	if (i <= start)
	{
		if ((str = malloc(sizeof(char) * 1)) == NULL)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	x = ft_taille_malloc(i, start, len);
	if ((str = malloc(sizeof(char) * x + 1)) == NULL)
		return (NULL);
	i = 0;
	while (s[i + start] != '\0' && i != len)
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	if (!s)
		return (NULL);
	if (c == '\0')
	{
		while (s[i] != '\0')
			i++;
		return ((char*)(s + i));
	}
	i = 0;
	if (s)
		while (s[i] != '\0')
		{
			if (s[i] == c)
				return ((char*)(s + i));
			i++;
		}
	return (0);
}
