/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 12:55:43 by redarnet          #+#    #+#             */
/*   Updated: 2020/07/17 20:55:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	algo2bis(t_data *data)
{
	double wallx;

	if (data->side == 0)
		wallx = data->py + data->perwall * data->raydiry;
	else
		wallx = data->px + data->perwall * data->raydirx;
	return (wallx);
}

void	algo2(t_data *data)
{
	int		lineheight;
	int		drawstart;
	int		tex;
	double	wallx;

	tex = 64;
	lineheight = (data->y / data->perwall);
	drawstart = -lineheight / 2 + data->y / 2;
	if (drawstart < 0)
		drawstart = 0;
	data->drawend = lineheight / 2 + data->y / 2;
	if (data->drawend >= data->y)
		data->drawend = data->y - 1;
	wallx = algo2bis(data);
	wallx -= (int)wallx;
	data->texx = (wallx * (double)tex);
	if (data->side == 0 && data->raydirx > 0)
		data->texx = tex - data->texx - 1;
	if (data->side == 1 && data->raydiry < 0)
		data->texx = tex - data->texx - 1;
	data->step = 1.0 * tex / lineheight;
	data->texpos = (drawstart - data->y / 2 + lineheight / 2) * data->step;
	data->y2 = drawstart;
	data->texnum = data->map2[data->mapx][data->mapy];
}
