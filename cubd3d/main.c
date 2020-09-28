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

void rotate_start(struct data_s *data, char c)
{
	double rotspeed;
	double olddirx;
	double oldplanex;


	rotspeed = 0;
	if (c == 'S')
		rotspeed = 3.2;
	if ( c == 'E')
		rotspeed = 1.6;
	if ( c == 'O')
		rotspeed = -1.6;
	olddirx = data->dirX;
                data->dirX = data->dirX * cos(-rotspeed) - data->dirY * sin(-rotspeed);
                data->dirY = olddirx * sin(-rotspeed) + data->dirY * cos(-rotspeed);
                oldplanex = data->planeX;
                data->planeX = data->planeX * cos(-rotspeed) -
                                data->planeY * sin(-rotspeed);
                data->planeY = oldplanex * sin(-rotspeed) +
                                data->planeY * cos(-rotspeed);
}

void	pos_perso(struct data_s *data)
{
	int x;
	int y;

	x = 0;
	y = 0;
	data->numsprite = 0;
	while (data->map[y] != 0)
	{
		x = 0;
		while (data->map[y][x] != '\0')
		{
			if ((data->map[y][0] != 'F') && (data->map[y][0] != 'C') && (data->map[y][0] != 'R'))
			if (data->map[y][x] == '2')
				data->numsprite = data->numsprite + 1;
			if (data->map[y][x] == 'N' || data->map[y][x] == 'S' ||
			data->map[y][x] == 'E' || data->map[y][x] == 'O')
			{
				data->py = x + 1.5;
				data->px = y + 1.5;
				rotate_start(data, data->map[y][x]);
			}
			x++;
		}
		y++;
	}
	data->numsprite = 2;
//	ft_putnbr_fd(data->numsprite, 1);
}

int	ft_quit(data_t *data)
{
	ft_putstr_fd("o", 1);
//	free(data->zbuffer);
	free(data->text_nord[0]);
	free(data->text_nord[1]);
	free(data->text_nord[2]);
	free(data->text_nord[3]);
	free(data->text_nord[4]);
	free(data->sprite);
	free(data->map);
	exit(5);
	return (0);
}

int	**change_map(char **map, int count)
{
	int i;
	int y;
	int **str;
	int x;
	int z;

	ft_putchar_fd(map[7][0], 1);
	ft_putchar_fd(map[8][0], 1);
	i = count;
	y = 0;
	while (map[i] != 0)
		i++;
	str = (int**)malloc(sizeof(int*) * i + 1);
	i = count;
	while (map[i] != 0)
	{
		y = 0;
		while (map[i][y] != '\0')
			y++;
		str[i + 1] = (int*)malloc(sizeof(int) * y + 1);
		i++;
	}
	x = count;
	z = 0;
	while (map[x] != 0)
	{
		z = 0;
		while (map[x][z] != '\0')
		{
			str[x  + 1][z + 1] = map[x][z] - '0';
		/*	
			if ((str[x- 7 + 1][z + 1] == 'N' - 48)
			    || (str[x + 1][z + 1] == 'S' - 48)
			    || (str[x + 1][z + 1] == 'O' - 48)
			    || (str[x + 1][z + 1] == 'E' - 48))
				str[x + 1][z + 1] = 0;
			if (x == i - 1)
				str[x- 6  + 1][z + 1] = 1;
			*/
				
			z++;
		}
		x++;
	}
	return (str);
}

void	tex_sprite(data_t *data)
{
	struct sprite_s	*sprite;
	int	i;
	int	y;
	int	z;

	y = 0;
	z = 0;
	i = 0;
	data->sprite = (sprite_t*)malloc(sizeof(sprite_t) * data->numsprite + 1);
	while (data->map[y] != 0)
	{
		i = 0;
		while (data->map[y][i] != '\0')
		{
			if ((data->map[y][0] != 'F') && (data->map[y][0] != 'C') && (data->map[y][0] != 'R'))
			if (data->map[y][i] == '2')
			{
				ft_putnbr_fd(i, 1);
				ft_putchar_fd('\n', 1);
				data->sprite[z].posy = y ;
				data->sprite[z].posx = i;
				data->map[y][i] = '0';
				z++;
			}
			i++;
		}
		y++;
	}
}

void	ft_free(data_t *data)
{
	free(data);
}
int	main(int argc, char **argv)
{
	data_t	data;
	int	i;
	t_t text;

	data.map = NULL;
	data.x = 0;
	data.y = 0;
	data.px = 0;
	data.py = 0;
	data.dirX = -1;
	data.dirY = 0;
	data.mapx = 0;
	data.mapy = 0;
	data.px = 0;
	data.py = 0;
	data.planeX = 0;
	data.planeY = 0.66;
	data.mapx = 0;
	data.mapy = 0;
	data.sidedirx = 0;
	data.sidediry = 0;
	data.side = 0;
	data.stepx = 0;
	data.y2 = 0;
	data.texPos = 0;
	data.stepy = 0;
	ft_pars_fichier(&data);
	pos_perso(&data);
	tex_sprite(&data);
	data.count2 = checkmap(data, data.map);
	data.map2 = change_map(data.map, data.count2);
	if (argc == 2 && !ft_strncmp(argv[1],"--save",6 ))
		save_bmp(data);
	else
	{
	if (data.x > 2580)
		data.x = 2580;
	if (data.y > 1400)
		data.y = 1400;
	data.mlx_ptr = mlx_init(&data);
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.x, data.y, "Cubd3d");
 	textures(&data);
	deal_key_map(112, &data);
	mlx_hook(data.win_ptr, 2, (1L << 0), &deal_key_map, &data);
	mlx_hook(data.win_ptr, 17, (1L << 7), ft_quit, &data);
	mlx_loop(data.mlx_ptr);
	mlx_clear_window(data.mlx_ptr, data.win_ptr);
	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	}
	free(data.text_nord[0]);
	free(data.text_nord[1]);
	free(data.text_nord[2]);
	free(data.text_nord[3]);
	free(data.text_nord[4]);
	return (0);
}
