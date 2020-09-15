/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 14:16:00 by redarnet          #+#    #+#             */
/*   Updated: 2020/07/22 01:21:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_t	textures_bis(t_t text, data_t *data)
{
	int l;
	int y;

	y = 0;
	while (y != 64)
	{
		l = *(int*)(text.ptr + text.size_l * text.x + data->bpp / 8 * y);
		text.texture[text.i][text.x][y] = l;
		y++;
	}
	return (text);
}

t_t	textures(data_t *data)
{
	t_t text;
	int h;
	int w;

	text.i = 0;
	while (text.i != 5)
	{
		data->img_ptr = mlx_new_image(data->mlx_ptr, data->x, data->y);
		data->img_data = (int*)mlx_get_data_addr(data->img_ptr,
		&data->bpp, &text.size_l, &text.endian);
		if (!(text.z = mlx_xpm_file_to_image(data->mlx_ptr,
		data->text_nord[text.i], &h, &w)))
			ft_error("bad textures");
		text.ptr = mlx_get_data_addr(text.z,
		&data->bpp, &text.size_l, &text.endian);
		text.x = 0;
		text.y = 0;
		while (text.x != 64)
		{
			text.y = 0;
			text = textures_bis(text, data);
			text.x++;
		}
		text.i++;
	}
	return (text);
}
