/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erreur.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 12:42:07 by redarnet          #+#    #+#             */
/*   Updated: 2020/03/04 13:23:37 by redarnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_error()
{
	ft_putstr_fd("error\n", 1);
	exit(5);
}

void	error_map(char **str)	
{
	int i;
	int y;

	i = 0;
	y = 0;
	while (str[0][i] != '\0')
	{
		if (str[0][i] != '1')
			ft_error();
		i++;
	}
	i = 0;
	while (str[y] != 0)
	{
		i = 0;
		while (str[y][i] != '\0')
			i++;
		if (str[y][i-1] != '1')
			ft_error();
		y++;
	}
	i = 0;
	while (str[y - 1][i] != '\0')
	{
		if (str[y - 1][i] != '1')
			ft_error();
		i++;
	}
}







