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

void	algobis(t_data *data)
{
	int hit;

	hit = 0;
	while (hit == 0)
	{
		if (data->sidedirx < data->sidediry)
		{
			data->sidedirx += data->deltadirx;
			data->mapx += data->stepx;
			data->side = 0;
		}
		else
		{
			data->sidediry = data->sidediry + data->deltadiry;
			data->mapy = data->mapy + data->stepy;
			data->side = 1;
		}
		if (data->map2[data->mapx][data->mapy] > 0)
			hit = 1;
	}
}

void	algobis2(t_data *data)
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

void	algo(t_data *data, int pix)
{
	double	camerax;

	data->mapx = (int)data->px;
	data->mapy = (int)data->py;
	camerax = 2 * pix / (double)(data->x) - 1;
	data->raydirx = data->dirx + data->planex * camerax;
	data->raydiry = data->diry + data->planey * camerax;
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
