void		ft_init_struct_save(t_storage *storage, t_save *s)
{
	s->size = 54 + 4 * storage->info->rx * storage->info->ry;
	s->unused = 0;
	s->offset_begin = 54;
	s->header_bytes = 40;
	s->plane = 1;
	s->bpixel = 32;
	s->fd = open("img.bmp", O_RDWR | O_CREAT, S_IRWXU | O_TRUNC);
	if (s->fd == -1)
		ft_management_error(9, "Error: open file .bmp\n");
}

void		ft_write_texture_bmp_file(t_storage *storage, int fd)
{
	int		y;
	int		x;
	int		line;

	y = 0;
	while (y < storage->info->ry)
	{
		x = 0;
		line = storage->info->rx * (storage->info->ry - y);
		while (x < storage->info->rx)
		{
			write(fd, &storage->mlx->data_img[line * 4], 4);
			line++;
			x++;
		}
		y++;
	}
}

void		ft_write_bmp_file(t_storage *storage)
{
	t_save	s;

	ft_init_struct_save(storage, &s);
	write(s.fd, "BM", 2);
	write(s.fd, &s.size, sizeof(int));
	write(s.fd, &s.unused, sizeof(int));
	write(s.fd, &s.offset_begin, sizeof(int));
	write(s.fd, &s.header_bytes, sizeof(int));
	write(s.fd, &storage->info->rx, sizeof(int));
	write(s.fd, &storage->info->ry, sizeof(int));
	write(s.fd, &s.plane, sizeof(short int));
	write(s.fd, &s.bpixel, sizeof(short int));
	write(s.fd, &s.unused, sizeof(int));
	write(s.fd, &s.unused, sizeof(int));
	write(s.fd, &s.unused, sizeof(int));
	write(s.fd, &s.unused, sizeof(int));
	write(s.fd, &s.unused, sizeof(int));
	write(s.fd, &s.unused, sizeof(int));
	ft_write_texture_bmp_file(storage, s.fd);
	close(s.fd);
}

void		ft_save(t_info *info_map, t_mlx *mlx)
{
	ft_init_struct_player(&player);
	if ((mlx->ptr = mlx_init()) == NULL)
		ft_management_error(9, "Error: init mlx fail\n");
	if ((mlx->win = mlx_new_window(mlx->ptr, info_map->rx,
		info_map->ry, "Save")) == NULL)
		ft_management_error(9, "Error: Windows fail\n");
	ft_init_texture(&storage, texture, 64, 64);
	ft_expose(&storage);
	ft_write_bmp_file(&storage);
	ft_exit_prog(&storage);
}
