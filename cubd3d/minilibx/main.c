#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct    data_s
{
    void          *mlx_ptr;
    void          *mlx_win;
    void	*mlx_image;
    int	*img_data;
    unsigned long 	img_color;
}                 data_t;

int main(void)
{
    data_t        data;
    int bpp;
    int size_l;
    int endian;

    if ((data.mlx_ptr = mlx_init()) == NULL)
        return (EXIT_FAILURE);
   data.mlx_win =  mlx_new_window(data.mlx_ptr, 500, 500, "Hello world");
   data.mlx_image = mlx_new_image(data.mlx_ptr, 500, 500);
   data.img_data = (int *)mlx_get_data_addr( data.mlx_image, &bpp, &size_l, &endian);
   data.img_color = mlx_get_color_value(data.mlx_ptr, 0xFFFFFFF);
   data.img_data[20*5 + 1] = 0xFFFFFFF;
   mlx_string_put(data.mlx_ptr, data.mlx_win, 15, -5, 5, "bonjour");
   mlx_put_image_to_window(data.mlx_ptr,data.mlx_win, data.mlx_image, 0,0);
    mlx_loop(data.mlx_ptr);
    return (EXIT_SUCCESS);
}
