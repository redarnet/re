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

int		ft_walldir(struct s_data data)
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
	return (walldir);
}

void	ft_algo(struct s_data data, int *img_data2,
		int texheight, double *zbuffer)
{
	int		pix;
	int		zo;
	int		texy;
	int		color;

	pix = 0;
	while (pix != data.x)
	{
		color = 0;
		algo(&data, pix);
		algo2(&data);
		data.walldir = ft_walldir(data);
		while (data.y2 < data.drawend)
		{
			zo = data.texpos;
			texy = zo;
			data.texpos += data.step;
			color = data.text.texture[data.walldir][0][texheight
		* texy + data.texx];
			img_data2[data.y2 * data.x + pix] = color;
			data.y2++;
		}
		zbuffer[pix] = data.perwall;
		pix++;
	}
}

t_data	*lmlx_new_image(void *mlx_ptr, void *win_ptr, int width, int height)
{
	t_data	*new;
	int		trsh;
	int		bpp;
	int		endian;

	bpp = 32;
	endian = 1;
	if (!(new = (t_data*)malloc(sizeof(t_data))))
		return (NULL);
	new->x = width;
	new->y = height;
	new->mlx_ptr = mlx_ptr;
	new->win_ptr = win_ptr;
	if (!(new->img_ptr = mlx_new_image(mlx_ptr, width, height)))
	{
		free(new);
		return (NULL);
	}
	new->img_data = (int*)mlx_get_data_addr(new->img_ptr, &bpp, &trsh, &endian);
	return (new);
}

void	lmlx_destroy_image(t_data *img)
{
	mlx_destroy_image(img->mlx_ptr, img->img_ptr);
	free(img);
}

void	ft_draw_walls(struct s_data data)
{
	int		texheight;
	t_data	*img;

	img = lmlx_new_image(data.mlx_ptr, data.win_ptr, data.x, data.y);
	texheight = 64;
	plafond(img, &data);
	sol(img, &data);
	ft_algo(data, img->img_data, texheight, data.zbuffer);
	ft_sprite(data, img->img_data);
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img_ptr, 0, 0);
	lmlx_destroy_image(img);
}
