/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 14:44:11 by redarnet          #+#    #+#             */
/*   Updated: 2020/07/22 13:19:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		write_file(int fd, t_bmp bmp)
{
	int x;
	int y;
	int	mix_planes_bpp;

	y = bmp.h - 1;
	mix_planes_bpp = bmp.bpp;
	mix_planes_bpp = (mix_planes_bpp << 16) + bmp.planes;
	ft_putstr_fd(bmp.magic, fd);
	write(fd, &bmp.size_file, 4);
	write(fd, &bmp.app_spe, 4);
	write(fd, &bmp.data_offset, 4);
	write(fd, &bmp.size_dib, 4);
	write(fd, &bmp.w, 4);
	write(fd, &bmp.h, 4);
	write(fd, &mix_planes_bpp, 4);
	write(fd, &bmp.padding_trash, 8);
	write(fd, &bmp.padding_trash, 8);
	write(fd, &bmp.padding_trash, 8);
	while (y >= 0)
	{
		x = 0;
		while (x < bmp.w)
			write(fd, &(bmp.data_ptr[(y * bmp.w) + x++]), 4);
		y--;
	}
}

t_bmp		init_bmp(struct s_data *data)
{
	t_bmp bmp;

	bmp.magic[0] = 'B';
	bmp.magic[1] = 'M';
	bmp.magic[2] = '\0';
	bmp.app_spe = 0;
	bmp.data_offset = 54;
	bmp.size_dib = 40;
	bmp.w = data->x;
	bmp.h = data->y;
	bmp.planes = 1;
	bmp.bpp = 32;
	bmp.size_file = bmp.data_offset + ((bmp.w * bmp.h) * 4);
	bmp.data_ptr = data->img_data;
	bmp.padding_trash = 0;
	return (bmp);
}

void		save_bmp(struct s_data data)
{
	int		fd;
	int		texheight;
	t_data	*img;
	t_bmp	bmp;

	texheight = 64;
	if ((fd = open("save.bmp", O_RDWR | O_CREAT, S_IRWXU)) == -1)
		ft_error2("open");
	img = lmlx_new_image(data.mlx_ptr, data.win_ptr, data.x, data.y);
	texheight = 64;
	plafond(img, &data);
	sol(img, &data);
	ft_algo(data, img->img_data, texheight, data.zbuffer);
	ft_sprite(data, img->img_data);
	bmp = init_bmp(img);
	write_file(fd, bmp);
	close(fd);
	lmlx_destroy_image(img);
}
