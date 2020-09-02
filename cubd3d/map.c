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

void	deal_key_map2(int key, data_t *data)
{
	double movespeed;
	double rotspeed;

	movespeed = 0.07;
	rotspeed = 0.06;
	if (key == key_w)
	{
		if (data->map2[(int)(data->px + data->dirX
		* movespeed)][(int)(data->py)] < 1)
			data->px += data->dirX * movespeed;
		if (data->map2[(int)(data->px)][(int)(data->py + data->dirY
		* movespeed)] < 1)
			data->py += data->dirY * movespeed;
	}
	if (key == key_s)
	{
		if (data->map2[(int)(data->px - data->dirX
		* movespeed)][(int)(data->py)] < 1)
			data->px -= data->dirX * movespeed;
		if (data->map2[(int)(data->px)][(int)(data->py - data->dirY
		* movespeed)] < 1)
			data->py -= data->dirY * movespeed;
	}
}

void deal_key_map3(int key, data_t *data)
{
	double movespeed;
	double rotspeed;
	double olddirx;
	double oldplanex;

	movespeed = 0.07;
	rotspeed = 0.06;
	if (key == key_d)
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
}

int	deal_key_map(int key, data_t *data)
{
	double movespeed;
	double rotspeed;
	double olddirx;
	double oldplanex;

	//remplir_blanc(*data);
	//plafond(data);
	// afficher_mur(5, data);
	movespeed = 0.07;
	rotspeed = 0.06;
	deal_key_map2(key, data);
	deal_key_map3(key, data);
	if (key == key_a)
	{
		olddirx = data->dirX;
		data->dirX = data->dirX * cos(rotspeed) - data->dirY * sin(rotspeed);
		data->dirY = olddirx * sin(rotspeed) + data->dirY * cos(rotspeed);
		oldplanex = data->planeX;
		data->planeX = data->planeX * cos(rotspeed) -
				data->planeY * sin(rotspeed);
		data->planeY = oldplanex * sin(rotspeed) + data->planeY * cos(rotspeed);
	}
	ft_draw_walls(*data, key);
	return (0);
}
