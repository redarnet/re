/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 12:43:40 by redarnet          #+#    #+#             */
/*   Updated: 2020/03/02 15:36:28 by redarnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_next_n(char *str)
{
	int i;

	i = 0;
	if (str)
		while (str[i] != '\n')
			i++;
	return (i);
}

int		ft_next_line(char **str, char **line)
{
	char *tmp;

	if (ft_strchr(*str, '\n'))
	{
		if ((*line = ft_substr(*str, 0, ft_next_n(*str))) == NULL)
			return (-1);
		tmp = *str;
		if ((*str = ft_substr(tmp, ft_next_n(tmp) + 1, ft_strlen(tmp))) == NULL)
		{
			free(tmp);
			tmp = NULL;
			return (-1);
		}
		free(tmp);
		tmp = NULL;
	}
	else
	{
		*line = ft_substr(*str, 0, ft_strlen(*str));
		free(*str);
		*str = NULL;
	}
	return (0);
}

int		ft_join(char **str, int fd)
{
	char		*tmp;
	char		buff[BUFFER_SIZE + 1];
	int			ret;

	ret = 0;
	while (!(ft_strchr(*str, '\n')) && (ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = *str;
		if ((*str = ft_strjoin(tmp, buff)) == NULL)
		{
			free(tmp);
			tmp = NULL;
			return (-1);
		}
		free(tmp);
		tmp = NULL;
	}
	if (ret < 0)
		return (-1);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*str = NULL;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (ft_join(&str, fd) == -1)
		return (-1);
	if ((ft_next_line(&str, line)) == -1)
		return (-1);
	if (!(str))
	{
		if (*line == NULL)
			*line = ft_substr("", 0, 0);
		return (0);
	}
	return (1);
}
