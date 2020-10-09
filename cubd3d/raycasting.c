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

void	move2(int key, t_data *data)
{
	double movespeed;

	movespeed = 0.2;
	if (key == KEY_W)
	{
		if (move_pos(data->map2[(int)(data->px - data->diry
						* movespeed)][(int)(data->py)]))
			data->px -= data->diry * movespeed * 0.5;
		if (move_pos(data->map2[(int)(data->px)][(int)(data->py + data->dirx
						* movespeed)]))
			data->py += data->dirx * movespeed * 0.5;
	}
	if (key == KEY_D)
	{
		if (move_pos(data->map2[(int)(data->px + data->diry
						* movespeed)][(int)(data->py)]))
			data->px += data->diry * movespeed * 0.5;
		if (move_pos(data->map2[(int)(data->px)][(int)(data->py - data->dirx
						* movespeed)]))
			data->py -= data->dirx * movespeed * 0.5;
	}
}

void	move(int key, t_data *data)
{
	double movespeed;

	movespeed = 0.2;
	if (key == KEY_A)
	{
		if (move_pos(data->map2[(int)(data->px + data->dirx
						* movespeed)][(int)(data->py)]))
			data->px += data->dirx * movespeed * 0.5;
		if (move_pos(data->map2[(int)(data->px)][(int)(data->py + data->diry
						* movespeed)]))
			data->py += data->diry * movespeed * 0.5;
	}
	if (key == KEY_S)
	{
		if (move_pos(data->map2[(int)(data->px - data->dirx
						* movespeed)][(int)(data->py)]))
			data->px -= data->dirx * movespeed * 0.5;
		if (move_pos(data->map2[(int)(data->px)][(int)(data->py - data->diry
						* movespeed)]))
			data->py -= data->diry * movespeed * 0.5;
	}
	move2(key, data);
}

void	rotate(int key, t_data *data, double rotspeed)
{
	double olddirx;
	double oldplanex;

	if (key == KEY_FD)
	{
		olddirx = data->dirx;
		data->dirx = data->dirx * cos(-rotspeed) - data->diry * sin(-rotspeed);
		data->diry = olddirx * sin(-rotspeed) + data->diry * cos(-rotspeed);
		oldplanex = data->planex;
		data->planex = data->planex * cos(-rotspeed) -
			data->planey * sin(-rotspeed);
		data->planey = oldplanex * sin(-rotspeed) +
			data->planey * cos(-rotspeed);
	}
	if (key == KEY_FG)
	{
		olddirx = data->dirx;
		data->dirx = data->dirx * cos(rotspeed) - data->diry * sin(rotspeed);
		data->diry = olddirx * sin(rotspeed) + data->diry * cos(rotspeed);
		oldplanex = data->planex;
		data->planex = data->planex * cos(rotspeed) -
			data->planey * sin(rotspeed);
		data->planey = oldplanex * sin(rotspeed) + data->planey * cos(rotspeed);
	}
}

int		deal_key_map(int key, t_data *data)
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
