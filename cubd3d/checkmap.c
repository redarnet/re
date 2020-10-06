/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 14:44:11 by redarnet          #+#    #+#             */
/*   Updated: 2020/07/22 13:19:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check2_bis(data_t *data, char c, int x, int y)
{
	int x1;
	int y1;

	x1 = x;
	y1 = y;
	if (c == '0')
	{
		while (y1 != data->count2 + 1)
		{
			y1--;
			if (data->map[y1][x1] == '1')
				break ;
			if (data->map[y1][x1] == ' ' || y1 < data->count2)
				ft_error("erreur ap", data);
		}
	}
}

void	ft_check2(data_t *data, char c, int x, int y)
{
	int x1;
	int y1;

	x1 = x;
	y1 = y;
	if (c == '0')
	{
		while (data->map[y1] != 0)
		{
			if (data->map[y1][x1] == '1')
				break ;
			if (data->map[y1][x1] == ' ' || data->map[y1 + 1] == 0)
				ft_error("erreur mmmap", data);
			y1++;
		}
	}
	ft_check2_bis(data, data->map[y][x], x, y);
}

void	ft_check(data_t *data, char c, int x, int y)
{
	int x1;

	if (c != 'N' && c != 'S' && c != 'E' && c != 'O'
			&& c != '1' && c != ' ' && c != '0' && c != '\0')
		ft_error("eerreur map", data);
	if (c == 'N' || c == 'S' || c == 'E' || c == 'O')
	{
		if (data->count > 0)
			ft_error("erreur map", data);
		data->count = 1;
	}
	x1 = x;
	if (c == '0')
		while (data->map[y][x1] != '\0')
		{
			x1++;
			if (data->map[y][x1] == '1')
				break ;
			if (data->map[y][x1] == ' ' || data->map[y][x1 + 1] == '\0')
				ft_error("erreur mmmap", data);
		}
	ft_check2(data, c, x, y);
}

void	checkmap2(data_t *data)
{
	int x;
	int y;

	y = data->count2;
	while (data->map[y] != 0)
	{
		x = 0;
		while (data->map[y][x] != '\0')
		{
			x++;
		}
		y++;
	}
	y = data->count2;
	while (data->map[y] != 0)
	{
		x = 0;
		while (data->map[y][x] != '\0')
		{
			ft_check(data, data->map[y][x], x, y);
			x++;
		}
		y++;
	}
}

int	start_map(struct data_s data)
{
	int x;
	int y;

	data.count2 = 0;
	data.count = 0;
	x = 0;
	y = 0;
	while (data.map[y] != 0)
	{
		x = 0;
		while (data.map[y][x] != '\0')
		{
			if ((data.map[y][0] != 'R') &&
			(data.map[y][0] != 'F') && (data.map[y][0] != 'C'))
				if (data.map[y][x] == '1' && data.count2 == 0)
					data.count2 = y;
			x++;
		}
		y++;
	}
	return (data.count2);
}
