#include "cub3d.h"

void save()
{
	ft_putstr_fd("1", 1);
}

static void		write_file(int fd, t_bmp bmp)
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
static t_bmp	init_bmp(struct data_s *data)
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

void save_bmp(struct data_s data)
{
	int fd;
	int texheight;
	double *zbuffer;
	int size_l;
	int endian;
	t_t text;
	t_bmp bmp;

	texheight = 64;
	zbuffer = (double*)malloc(sizeof(double) * 500 + 1);
	if((fd = open("save.bmp", O_RDWR | O_CREAT, S_IRWXU)) == -1)
	save();
 	data.mlx_ptr = mlx_init(&data);
        data.img_ptr = mlx_new_image(data.mlx_ptr, 500, 500);
	data.img_data = (int*)mlx_get_data_addr(data.img_ptr,
                &data.bpp, &size_l, &endian);
	 text = textures(&data);
	 sol(&data);
	 plafond(&data);
	ft_algo(data, data.img_data, texheight , zbuffer);
	ft_sprite(data, zbuffer, data.img_data, text);
	 bmp = init_bmp(&data);
	 write_file(fd, bmp);
	 close(fd);

}
