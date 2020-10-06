/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 14:44:11 by redarnet          #+#    #+#             */
/*   Updated: 2020/07/22 13:19:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_quit(data_t *data)
{
	int i;

	i = 0;
	while (i != 4)
	{
		if (data->text_nord[i])
			free(data->text_nord[i]);
		i++;
	}
	if (data->sprite)
		free(data->sprite);
	if (data->map2)
		ft_free_map(data->map2, data);
	exit(5);
	return (0);
}

void	init_ray(struct data_s *data)
{
	data->map = NULL;
	data->x = 0;
	data->y = 0;
	data->px = 0;
	data->py = 0;
	data->dirX = -1;
	data->dirY = 0;
	data->mapx = 0;
	data->size_free = 0;
	data->mapy = 0;
	data->px = 0;
	data->py = 0;
	data->planeX = 0;
	data->planeY = 0.66;
	data->mapx = 0;
	data->mapy = 0;
	data->sidedirx = 0;
	data->sidediry = 0;
	data->side = 0;
	data->stepx = 0;
	data->y2 = 0;
	data->texPos = 0;
	data->stepy = 0;
	data->count = 0;
}

void	cubd3d(struct data_s *data, char **argv, int argc)
{
	if (argc == 2 && !ft_strncmp(argv[1], "--save", 6))
	{
		data->mlx_ptr = mlx_init(&data);
		data->win_ptr = mlx_new_window(data->mlx_ptr,
			data->x, data->y, "Cubd3d");
		textures(data);
		save_bmp(*data);
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	}
	else
	{
		if (data->x > 2580)
			data->x = 2580;
		if (data->y > 1400)
			data->y = 1400;
		if ((data->mlx_ptr = mlx_init(&data)) == NULL)
			ft_error("window error", data);
		if ((data->win_ptr = mlx_new_window(data->mlx_ptr,
			data->x, data->y, "Cubd3d"))== NULL)
		ft_error("window error", data);
		textures(data);
		deal_key_map(112, data);
		mlx_hook(data->win_ptr, 2, (1L << 0), &deal_key_map, data);
		mlx_hook(data->win_ptr, 17, (1L << 7), ft_quit, &data);
		mlx_loop(data->mlx_ptr);
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free(data);
	}
	ft_quit(data);
}

int		main(int argc, char **argv)
{
	data_t	data;
	char	**str;

	init_ray(&data);
	ft_pars_fichier(&data, argv[1]);
	data.count2 = start_map(data);
	pos_perso(&data);
	tex_sprite(&data);
	str = data.map;
	checkmap2(&data);
	data.map2 = change_map(str, data.count2, &data);
	if (data.map)
		ft_free_m(data.map);
	cubd3d(&data, argv, argc);
	ft_quit(&data);
	return (0);
}
