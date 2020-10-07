/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 14:44:11 by redarnet          #+#    #+#             */
/*   Updated: 2020/07/22 13:19:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	abss(double a)
{
	if (a < 0)
		a = -a;
	return (a);
}

char	*ft_strcat(char *s1, const char *s2)
{
	int i;
	int j;

	i = 0;
	while (s1[i] != '\0')
		i++;
	j = 0;
	while (s2[j] != '\0')
	{
		s1[i + j] = s2[j];
		j++;
	}
	s1[i + j] = '\0';
	return (s1);
}

char	*ft_strcpy(char *dst, const char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char *str;

	if (!s2 || !s2)
		return (NULL);
	str = malloc(sizeof(ft_strlen(s1) + ft_strlen(s2)));
	str = ft_strcpy(str, s1);
	str = ft_strcat(str, s2);
	free(s1);
	free(s2);
	return (str);
}

int		ft_strsub_bis(char *line, data_t *data)
{
	int i;

	i = 3;
	if (line[0] == 'N')
		if (line[1] != 'O')
			ft_error("syntaxe configh", data);
	if (line[0] == 'S')
	{
		if (line[1] == ' ')
			i = 2;
		if (line[1] != 'O' && line[1] != ' ')
			ft_error("synetaxe configh", data);
	}
	if (line[0] == 'W')
		if (line[1] != 'E')
			ft_error("syntaxe configh", data);
	if (line[0] == 'E')
		if (line[1] != 'A')
			ft_error("syntaxe configh", data);
	return (i);
}
