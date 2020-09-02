/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:12:23 by redarnet          #+#    #+#             */
/*   Updated: 2020/08/18 01:23:32 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	algobis(data_t *data)
{
	int hit;

	hit = 0;
	while (hit == 0)
	{
		if (data->sidediry <= 0 || (data->sidedirx
			>= 0 && data->sidedirx < data->sidediry))
		{
			data->sidedirx = data->sidedirx + data->deltadirx;
			data->mapx = data->mapx + data->stepx;
			data->side = 0;
		}
		else
		{
			data->sidediry = data->sidediry + data->deltadiry;
			data->mapy = data->mapy + data->stepy;
			data->side = 1;
		}
		if (data->map2[data->mapx][data->mapy] != 0)
			hit = 1;
	}
}

void	algobis2(data_t *data)
{
	if (data->raydirx < 0)
	{
		data->stepx = -1;
		data->sidedirx = (data->px - data->mapx) * data->deltadirx;
	}
	else
	{
		data->stepx = 1;
		data->sidedirx = (data->mapx + 1 - data->px) * data->deltadirx;
	}
	if (data->raydiry < 0)
	{
		data->stepy = -1;
		data->sidediry = (data->py - data->mapy) * data->deltadiry;
	}
	else
	{
		data->stepy = 1;
		data->sidediry = (data->mapy + 1 - data->py) * data->deltadiry;
	}
}

void	algo(data_t *data, int pix, double dirx, double diry)
{
	float	ratio;
	int		side;
	int		hit;
	float	perwall;
	double	camerax;

	data->mapx = (int)data->px;
	data->mapy = (int)data->py;
	camerax = 2 * pix / (double)(500) - 1;
	ratio = ((float)pix - data->x / 2) / data->x / 2;
	data->raydirx = data->dirX + data->planeX * camerax;
	data->raydiry = data->dirY + data->planeY * camerax;
	data->deltadirx = sqrt(1 + (data->raydiry * data->raydiry)
		/ (data->raydirx * data->raydirx));
	data->deltadiry = sqrt(1 + (data->raydirx * data->raydirx) /
		(data->raydiry * data->raydiry));
	algobis2(data);
	algobis(data);
	if (data->side == 0)
		data->perwall = (data->mapx - data->px + (1 - data->stepx) / 2)
			/ data->raydirx;
	else
		data->perwall = (data->mapy - data->py + (1 - data->stepy) / 2) /
			data->raydiry;
}
