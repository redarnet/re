/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:12:23 by redarnet          #+#    #+#             */
/*   Updated: 2020/03/12 14:46:23 by redarnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void algo(data_t *data, int pix,double dirX, double dirY)
{
	float ratio;
	float deltadirx;
	float deltadiry;
	float sidediry;
	float sidedirx;
	int stepx;
	int stepy;
	int side;
	int hit;
	float perwall;

	data->mapx = (int)data->px;
	data->mapy = (int)data->py;
	double camerax = 2* pix/(double)(500) -1;
	ratio = ((float)pix-data->x/2)/data->x/2;
	 data->raydirx = data->dirX + data->planeX * camerax;
     data->raydiry = data->dirY + data->planeY * camerax;
//	 data->dirx = cos(data->angle)/2 + cos(data->angle - M_PI/2) * ratio;
//	data->diry = sin(data->angle)/2 + sin(data->angle - M_PI/2) * ratio;
	deltadirx = sqrt(1 + (data->raydiry * data->raydiry) / (data->raydirx * data->raydirx));
	deltadiry = sqrt(1 + (data->raydirx * data->raydirx) /(data->raydiry * data->raydiry));
	if (data->raydirx < 0)
	{
		stepx = -1;
		sidedirx = (data->px - data->mapx) * deltadirx;
	}
	else
	{
		stepx = 1;
		sidedirx =  (data->mapx + 1 - data->px) * deltadirx;
	}
	if (data->raydiry < 0)
	{
		stepy = -1;
		sidediry = (data->py - data->mapy) * deltadiry;
	}
	else
	{
		stepy = 1;
		sidediry =  (data->mapy + 1 - data->py) * deltadiry;
	}
	hit = 0;
	while (hit == 0)
	{
		if (sidediry <= 0 || ( sidedirx >=0 && sidedirx < sidediry))
		{
			sidedirx =  sidedirx + deltadirx;
			data->mapx =  data->mapx + stepx;
			data->side = 0;
		}
		else
		{
			sidediry = sidediry +  deltadiry;
			data->mapy =  data->mapy +stepy;
			data->side = 1;
		}
		if (data->map2[data->mapx][data->mapy] != 0)
			hit = 1;
	}
	if (data->side == 0)
		data->perwall = (data->mapx - data->px + (1 -stepx)/2) / data->raydirx;
	else
		data->perwall = (data->mapy - data->py + (1 -stepy)/2) / data->raydiry;
}
