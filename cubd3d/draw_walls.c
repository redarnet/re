/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 13:37:36 by redarnet          #+#    #+#             */
/*   Updated: 2020/09/01 16:22:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ft_walldir(struct data_s data)
{
	int walldir;

	if (data.side == 1)
	{	
		if (data.mapy < data.py)
			walldir = 1;
		else
			walldir = 2;
	}
	else
	{	
		if (data.mapx < data.px)
			walldir = 3;
		else
			walldir = 0;
	}
	return walldir;
}

void	ft_algo(struct data_s data, int *img_data2,
		int texheight, double *zbuffer)
{
	int pix;
	int zo;
	int texy;
	int color;
	t_t text;

	text = textures(&data);
	pix = 0;
	while (pix != data.x)
	{
		color = 0;
		algo(&data, pix, data.dirX, data.dirY);
		algo2(&data);
		data.walldir = ft_walldir(data);
		while (data.y2 < data.drawEnd)
		{
			zo = data.texPos;
			texy = zo;
			data.texPos += data.step;
			color = text.texture[data.walldir][0][texheight * texy + data.texX];
			img_data2[data.y2 * data.x + pix] = color;
			data.y2++;
		}
		zbuffer[pix] = data.perwall;
		pix++;
	}
}

void	ft_draw_walls(struct data_s data, int key)
{
	int	texheight;
	double		*zbuffer;
	t_t		text;

	texheight = 64;
	text = textures(&data);
	zbuffer = (double*)malloc(sizeof(double) * data.x + 1);
	plafond(&data);
	sol(&data);
	ft_algo(data, data.img_data, texheight, zbuffer);
	ft_sprite(data, zbuffer, data.img_data, text);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, 0, 0);
}
