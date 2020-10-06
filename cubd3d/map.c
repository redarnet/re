/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 15:10:56 by redarnet          #+#    #+#             */
/*   Updated: 2020/08/05 17:20:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_start(struct data_s *data, char c)
{
	double rotspeed;
	double olddirx;
	double oldplanex;

	rotspeed = 0;
	if (c == 'S')
		rotspeed = 3.2;
	if (c == 'E')
		rotspeed = 1.6;
	if (c == 'O')
		rotspeed = -1.6;
	olddirx = data->dirX;
	data->dirX = data->dirX * cos(-rotspeed) - data->dirY * sin(-rotspeed);
	data->dirY = olddirx * sin(-rotspeed) + data->dirY * cos(-rotspeed);
	oldplanex = data->planeX;
	data->planeX = data->planeX * cos(-rotspeed) -
		data->planeY * sin(-rotspeed);
	data->planeY = oldplanex * sin(-rotspeed) +
		data->planeY * cos(-rotspeed);
}

void	pos_perso(struct data_s *data)
{
	int x;
	int y;

	y = data->count2;
	data->numsprite = 0;
	while (data->map[y] != 0)
	{
		x = 0;
		while (data->map[y][x] != '\0')
		{
				if (data->map[y][x] == '2')
					data->numsprite = data->numsprite + 1;
			if (data->map[y][x] == 'N' || data->map[y][x] == 'S' ||
					data->map[y][x] == 'E' || data->map[y][x] == 'O')
			{
				data->py = x + 1.5;
				data->px = y  -data->count2 + 1.5;
				ft_putnbr_fd(data->px, 1);
				rotate_start(data, data->map[y][x]);
			}
			x++;
		}
		y++;
	}
}

int		**change_map2(char **map, int **str, int count, int i)
{
	int x;
	int z;

	x = count;
	while (map[x] != 0)
	{
		z = 0;
		while (map[x][z] != '\0')
		{
			str[x - count+ 1][z + 1] = map[x][z] - '0';
			  if ((str[x -count + 1][z + 1] == 'N' - 48)
                                        || (str[x - count + 1][z + 1] == 'S' - 48)
                                        || (str[x - count + 1][z + 1] == 'O' - 48)
                                        || (str[x - count + 1][z + 1] == 'E' - 48))
                                str[x - count + 1][z + 1] = 0;
			z++;
		}
		x++;
	}
	return (str);
}

int		**change_map(char **map, int count, data_t *data)
{
	int i;
	int **str;
	int z;

	i = count;
	while(map[i] != 0)
		i++;
	i = i - count + 2;
	str = (int**)malloc(sizeof(int*) *(i));
	data->size_free = i;
	i = count;
	while (map[i] != 0)
	{
		z = 0;
		while(map[i][z] != '\0')
			z++;
		z++;
		str[i - count + 1] = (int*)malloc(sizeof(int) * z);
		i++;
	}
		str[i - count + 1] = (int*)malloc(sizeof(int) * 1);
	str = change_map2(map, str, count, i);
	return (str);
}
