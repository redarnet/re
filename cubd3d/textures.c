/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 14:44:11 by redarnet          #+#    #+#             */
/*   Updated: 2020/07/22 13:19:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	tex_sprite(data_t *data)
{
	int	i;
	int	y;
	int	z;

	y = data->count2;
	z = 0;
	data->sprite = (sprite_t*)malloc(sizeof(sprite_t) * data->numsprite + 1);
	while (data->map[y] != 0)
	{
		i = 0;
		while (data->map[y][i] != '\0')
		{
			if (data->map[y][i] == '2')
			{
				data->sprite[z].posy = y - data->count2 + 1.5;
				data->sprite[z].posx = i + 1.5;
				data->map[y][i] = '0';
				z++;
			}
			i++;
		}
		y++;
	}
}

void	lmlx_free_t_img(data_t *data)
{
	if (data)
	{
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
		free(data);
	}
}

data_t	*lmlx_xpm_to_img(void *mlx_ptr, char *path)
{
	data_t	*new;
	void	*temp;
	int		bpp;
	int		endian;

	bpp = 32;
	endian = 1;
	new = (data_t*)malloc(sizeof(data_t));
	new->mlx_ptr = mlx_ptr;
	new->win_ptr = NULL;
	new->x = 0;
	new->y = 0;
	temp = mlx_xpm_file_to_image(mlx_ptr, path, &new->x, &new->y);
	if (!(temp))
	{
		free(new);
		return (NULL);
	}
	new->img_ptr = temp;
	new->img_data = (int*)mlx_get_data_addr(temp,
			&new->bpp, &new->size_l, &endian);
	new->text.ptr = mlx_get_data_addr(temp,
			&new->bpp, &new->size_l, &endian);
	return (new);
}

t_t		textures_bis(data_t *img, data_t *data)
{
	int l;
	int y;

	y = 0;
	while (y != 64)
	{
		l = *(int*)(img->text.ptr + img->size_l *
				data->text.x + img->bpp / 8 * y);
		data->text.texture[data->text.i][data->text.x][y] = l;
		y++;
	}
	return (data->text);
}

void	textures(data_t *data)
{
	data_t	*img;

	data->text.i = 0;
	while (data->text.i != 5)
	{
		img = lmlx_xpm_to_img(data->mlx_ptr, data->text_nord[data->text.i]);
		data->text.x = 0;
		data->text.y = 0;
		while (data->text.x != 64)
		{
			data->text.y = 0;
			data->text = textures_bis(img, data);
			data->text.x++;
		}
		data->text.i++;
		lmlx_free_t_img(img);
	}
}
