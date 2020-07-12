/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 14:16:00 by redarnet          #+#    #+#             */
/*   Updated: 2020/03/11 11:46:45 by redarnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_t	textures(data_t  *data)
{
	t_t text;
	int x;
	int y;
	int l;
	int size_l;
	int endian;
	void *z;
	char *ptr;
	int h;
	int w;


	
	data->img_ptr = mlx_new_image(data->mlx_ptr, 500, 500);
	data->img_data = (int*)mlx_get_data_addr(data->img_ptr, &data->bpp, &size_l, &endian);
	z = mlx_xpm_file_to_image(data->mlx_ptr, data->text_west , &h, &w);
	ptr = mlx_get_data_addr(z, &data->bpp, &size_l, &endian);
	x = 0;
	l = 0;
	y = 0;
	while ( x != 64)
	{
		y = 0;
		while (y != 64)
		{
		l = *(int*)(ptr + size_l * x + data->bpp/8 * y);
		text.texture[3][x][y] = l;
		y++;
		}
	x++;
	}
	z = mlx_xpm_file_to_image(data->mlx_ptr, data->text_est , &h, &w);
	ptr = mlx_get_data_addr(z, &data->bpp, &size_l, &endian);
	x = 0;
	l = 0;
	y = 0;
	while ( x != 64)
	{
		y = 0;
		while (y != 64)
		{
		l = *(int*)(ptr + size_l * x + data->bpp/8 * y);
		text.texture[2][x][y] = l;
		y++;
		}
	x++;
	}
	z = mlx_xpm_file_to_image(data->mlx_ptr, data->text_nord , &h, &w);
	ptr = mlx_get_data_addr(z, &data->bpp, &size_l, &endian);
	x = 0;
	l = 0;
	y = 0;
	while ( x != 64)
	{
		y = 0;
		while (y != 64)
		{
		l = *(int*)(ptr + size_l * x + data->bpp/8 * y);
		text.texture[1][x][y] = l;
		y++;
		}
	x++;
	}
	z = mlx_xpm_file_to_image(data->mlx_ptr, data->text_sud , &h, &w);
	ptr = mlx_get_data_addr(z, &data->bpp, &size_l, &endian);
	x = 0;
	l = 0;
	y = 0;
	while ( x != 64)
	{
		y = 0;
		while (y != 64)
		{
		l = *(int*)(ptr + size_l * x + data->bpp/8 * y);
		text.texture[0][x][y] = l;
		y++;
		}
	x++;
	}
	z = mlx_xpm_file_to_image(data->mlx_ptr, "textures/barrel.xpm" , &h, &w);
	ptr = mlx_get_data_addr(z, &data->bpp, &size_l, &endian);
	x = 0;
	l = 0;
	y = 0;
	while ( x != 64)
	{
		y = 0;
		while (y != 64)
		{
		l = *(int*)(ptr + size_l * x + data->bpp/8 * y);
		text.texture[4][x][y] = l;
		y++;
		}
	x++;
	}






	return text;
}
