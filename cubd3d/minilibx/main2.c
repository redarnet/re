#include        <mlx.h>
#include        <stdlib.h>
#include        <stdio.h>
#include        <unistd.h>
#include <math.h>


void	ft_putchar(char c)
{
	write(1, &c, 1);
}

typedef struct data_s
{
	void	*mlx_ptr;
	void	*win_ptr;
	char 	x;
	void	*img_ptr;
	int test;
	int *img_data;
	int h;
	int w;
	unsigned long img_color;
}		data_t;



void	ft_remplir_carre(struct data_s data)
{
	int y;
	int x;

	y = 50;
	x  = 0;
	while (y != 200)
	{
		x = 0;
		while (x != 200)
		{
  			mlx_pixel_put(data.mlx_ptr, data.win_ptr, y , x, 0xFFFFFF);
			x++;
		}
		y++;
	}
}

void	ft_remplir_triangle(struct data_s data)
{
	int x;
	int y;
	int z;
	int w;

	y = 0;
	x = 0;
	w = 0;
	z = 0;
	while ( y != 500)
	{
		x = 0;
		while (x != 500)
		{
			if (x >= 250 && y == 250)
			mlx_pixel_put(data.mlx_ptr, data.win_ptr, x, y, 0xFFFFFF);
//			if ( y  == (x + 250)/2.2   ) 
//			mlx_pixel_put(data.mlx_ptr, data.win_ptr, x, y, 0xFFFFFF);
			if ( x <= 0.4  *y  && y <= 250 ) 
			mlx_pixel_put(data.mlx_ptr, data.win_ptr, x, y, 0xFFFFFF);
			if (   1 *y + 2.5 *x <=  500 && y >= 250 ) 
			mlx_pixel_put(data.mlx_ptr, data.win_ptr, x, y, 0xFFFFFF);
			if ( x  >= 0.6  *y  && y >= 250 ) 
			mlx_pixel_put(data.mlx_ptr, data.win_ptr, x, y, 0xFFFFFF);
			x++;
		}
		y++;
	}
}
void	ft_remplir(struct data_s data)
{
	int x;
	int y;

	 x = 0;
	 y = -1;

	 while (x != 499)
		{
  		mlx_pixel_put(data.mlx_ptr, data.win_ptr, y , x, 0xFFFFFF);
		x++;
	}
}

int expose_hook(void * param)
{
	data_t data;

  data.win_ptr = mlx_new_window(data.mlx_ptr, 500, 500 , "test");
  return 0;
}

int deal_key2(int key, void *param, struct data_s data)
{
 data. mlx_ptr = mlx_init(&data);
  data.win_ptr = mlx_new_window(data.mlx_ptr, 500, 500 , "test");
	ft_putchar('x');
  mlx_key_hook(data.win_ptr, deal_key2, (void *)&data);
	data.test = 0x40A497;
	return 0;
}

int deal_key(int key, data_t *data)
{
	int x;
	int y;
	int bpp;
	int size_l;
	int endian;
	void  *z;

	ft_putchar(key);
		ft_putchar('x');
		if (key == 'W')
		ft_remplir_carre( *data);
		data->img_ptr = mlx_new_image(data->mlx_ptr, 50, 50);
     data->img_data = (int*)mlx_get_data_addr( data->img_ptr, &bpp, &size_l, &endian);
		z =  mlx_xpm_file_to_image(data->mlx_ptr, "barrel.xpm", &data->w, &data->h);
		ft_putchar('y');

			if ( key == 'V')		
  			mlx_put_image_to_window(data->mlx_ptr,data->win_ptr, z,  50,  50);
	data->test = 0x40A497;
	return 0;
}

int loop_hook(void *param)
{
	
	return 0;
}

int mouse_hook(int button, int x, int y, void *param, struct data_s data)
{
	data. mlx_ptr = mlx_init(&data);
	 data.win_ptr = mlx_new_window(data.mlx_ptr, 500, 500 , "test");
	 return 0;
}

int     main()
{
	data_t data;

	int x;
	int y;
	int bpp;
	int size_l;
	int endian;
	data.x = 50;
	data.test = 0xFFFFFFF;
	x = -5;
	y = -250;
  
	data.h = 50;
	data.w = 50;
	ft_putchar(data.x);
 data. mlx_ptr = mlx_init(&data);
  data.win_ptr = mlx_new_window(data.mlx_ptr, 500, 500 , "test");
ft_putchar('x');
ft_remplir_triangle(data);
//ft_remplir(data);
//		ft_remplir_carre( data);
  mlx_string_put(data.mlx_ptr, data.win_ptr, 150 , 150, data.test, "boujour");
//  data.img_ptr = mlx_new_image(data.mlx_ptr, 40, 40);
  //   data.img_data = (int*)mlx_get_data_addr( data.img_ptr, &bpp, &size_l, &endian);
//   data.img_color = mlx_get_color_value(data.mlx_ptr, 0xFFFFFFF);
//   data.img_data[20*5 + 1] = 0xFFFFFFF;
//  mlx_put_image_to_window(data.mlx_ptr,data.win_ptr, data.img_ptr,  300,  300);
  mlx_key_hook(data.win_ptr, &deal_key, &data);
//  mlx_loop_hook(data.win_ptr, &loop_hook , &data);
//	 	mlx_key_hook(data.win_ptr, deal_key2, (void *)&data);
 // mlx_mouse_hook(data.win_ptr, mouse_hook 
  //mlx_expose_hook(data.win_ptr, expose_hook, (void *)&data);
  mlx_loop(data.mlx_ptr);
}
