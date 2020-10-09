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

int		ft_quit(t_data *data)
{

	exit(5);
	return (0);
}

void	init_ray(struct s_data *data)
{
	data->map = NULL;
	data->x = 0;
	data->y = 0;
	data->px = 0;
	data->py = 0;
	data->dirx = -1;
	data->diry = 0;
	data->mapx = 0;
	data->size_free = 0;
	data->mapy = 0;
	data->px = 0;
	data->py = 0;
	data->planex = 0;
	data->planey = 0.66;
	data->mapx = 0;
	data->mapy = 0;
	data->sidedirx = 0;
	data->sidediry = 0;
	data->side = 0;
	data->stepx = 0;
	data->y2 = 0;
	data->texpos = 0;
	data->stepy = 0;
	data->count = 0;
}

void	cubsave(struct s_data *data)
{
	if ((data->mlx_ptr = mlx_init(&data)) == NULL)
		ft_error("window error", data);
	if ((data->win_ptr = mlx_new_window(data->mlx_ptr,
		data->x, data->y, "Cubd3d")) == NULL)
		ft_error("window error", data);
	textures(data);
	save_bmp(*data);
}

void	cubd3d(struct s_data *data, char **argv, int argc)
{
	if (argc == 3 && !ft_strncmp(argv[2], "--save", 6))
		cubsave(data);
	else
	{
		if (data->x > 2580)
			data->x = 2580;
		if (data->y > 1400)
			data->y = 1400;
		if ((data->mlx_ptr = mlx_init(&data)) == NULL)
			ft_error("window error", data);
		if ((data->win_ptr = mlx_new_window(data->mlx_ptr,
						data->x, data->y, "Cubd3d")) == NULL)
			ft_error("window error", data);
		textures(data);
		deal_key_map(112, data);
		save_bmp(*data);
		mlx_hook(data->win_ptr, 17,(1L << 17), ft_quit, &data);
		mlx_hook(data->win_ptr, 2, (1L << 0), &deal_key_map, data);
		mlx_loop(data->mlx_ptr);
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free(data);
	}
	ft_quit(data);
}

int		main(int argc, char **argv)
{
	t_data	data;
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
