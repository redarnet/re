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

int		move_pos(int pos)
{
	if (pos == 1 || pos == 4)
		return (0);
	return (1);
}

void	move2(int key, data_t *data)
{
	double movespeed;

	movespeed = 0.2;
	if (key == KEY_W)
	{
		if (move_pos(data->map2[(int)(data->px - data->dirY
						* movespeed)][(int)(data->py)]))
			data->px -= data->dirY * movespeed * 0.5;
		if (move_pos(data->map2[(int)(data->px)][(int)(data->py + data->dirX
						* movespeed)]))
			data->py += data->dirX * movespeed * 0.5;
	}
	if (key == KEY_D)
	{
		if (move_pos(data->map2[(int)(data->px + data->dirY
						* movespeed)][(int)(data->py)]))
			data->px += data->dirY * movespeed * 0.5;
		if (move_pos(data->map2[(int)(data->px)][(int)(data->py - data->dirX
						* movespeed)]))
			data->py -= data->dirX * movespeed * 0.5;
	}
}

void	move(int key, data_t *data)
{
	double movespeed;

	movespeed = 0.2;
	if (key == KEY_A)
	{
		if (move_pos(data->map2[(int)(data->px + data->dirX
						* movespeed)][(int)(data->py)]))
			data->px += data->dirX * movespeed * 0.5;
		if (move_pos(data->map2[(int)(data->px)][(int)(data->py + data->dirY
						* movespeed)]))
			data->py += data->dirY * movespeed * 0.5;
	}
	if (key == KEY_S)
	{
		if (move_pos(data->map2[(int)(data->px - data->dirX
						* movespeed)][(int)(data->py)]))
			data->px -= data->dirX * movespeed * 0.5;
		if (move_pos(data->map2[(int)(data->px)][(int)(data->py - data->dirY
						* movespeed)]))
			data->py -= data->dirY * movespeed * 0.5;
	}
	move2(key, data);
}

void	rotate(int key, data_t *data, double rotspeed)
{
	double olddirx;
	double oldplanex;

	if (key == KEY_FD)
	{
		olddirx = data->dirX;
		data->dirX = data->dirX * cos(-rotspeed) - data->dirY * sin(-rotspeed);
		data->dirY = olddirx * sin(-rotspeed) + data->dirY * cos(-rotspeed);
		oldplanex = data->planeX;
		data->planeX = data->planeX * cos(-rotspeed) -
			data->planeY * sin(-rotspeed);
		data->planeY = oldplanex * sin(-rotspeed) +
			data->planeY * cos(-rotspeed);
	}
	if (key == KEY_FG)
	{
		olddirx = data->dirX;
		data->dirX = data->dirX * cos(rotspeed) - data->dirY * sin(rotspeed);
		data->dirY = olddirx * sin(rotspeed) + data->dirY * cos(rotspeed);
		oldplanex = data->planeX;
		data->planeX = data->planeX * cos(rotspeed) -
			data->planeY * sin(rotspeed);
		data->planeY = oldplanex * sin(rotspeed) + data->planeY * cos(rotspeed);
	}
}

int		deal_key_map(int key, data_t *data)
{
	double rotspeed;

	rotspeed = 0.2;
	if (key == 65307)
		ft_quit(data);
	rotate(key, data, rotspeed);
	move(key, data);
	ft_draw_walls(*data);
	return (0);
}
