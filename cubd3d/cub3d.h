#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include <math.h>
#include "minilibx-linux/mlx.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#define key_m 46
#define key_fd 65363
#define key_fg 65361
#define key_a 97
#define key_s 115
#define key_w 119
#define key_d 100


typedef struct t_s
{
	int texture[6][64][64];
	int i;
	int x;
	char *ptr;
	int y;
	int endian;
	void *z;
}	t_t;

typedef struct	s_bmp
{
	char		magic[3];
	int			size_file;
	int			app_spe;
	int			data_offset;
	int			size_dib;
	int			w;
	int			h;
	short int	planes;
	short int	bpp;
	int			*data_ptr;
	double		padding_trash;
}				t_bmp;
typedef struct sprite_s
{
	double posx;
	double posy;
	double spritex;
	double spritey;
	double invdet;
	double transformx;
	double transformy;
	int spritescreenx;
	int spriteheight;
	int drawstarty;
	int drawendy;
	int spritewidth;
	int drawstartx;
	int drawendx;
	int stripe;
	int texx;
	int texy;
	int color2;

}	sprite_t;


typedef struct data_s
{
	sprite_t *sprite;
	double zbuffer[500];
	t_t text;
	int texNum;
	int walldir;
	double texPos;
	int texX;
	void 	*mlx_ptr;
	int y2;
	void	*win_ptr;
	int	x;
	int	y;
	int **map2;
	char **map;
	int	couleur1;
	int	couleur2;
	int	couleur3;
	float px;
	float py;
	float speed;
	int couleur_sol;
	int couleur_plafond;
	double step;
	void *img_ptr;
	int *img_data;
	char *text_nord[5];
	int side;
	float dirX;
	float dirY;
	float raydirx;
	float raydiry;
	int mapx;
	int mapy;
	int drawEnd;
	double planeX;
	double planeY;
	float perwall;
	int bpp;
	int numsprite;
	float sidedirx;
	float sidediry;
	int stepx;
	int stepy;
	float deltadirx;
	float deltadiry;
	int count;
	int count2;
	int size_free;
	int size_l;

}		data_t;

void	textures(data_t *data);
int deal_key_map(int key, data_t *data);
void	algo(data_t *data, int pix);
void    ft_algo(struct data_s data, int *img_data2 , int texheight, double *zbuffer); 
void	algo2(data_t *data);
void	ft_sprite(struct data_s data, int *img_data2);
double abss(double a);
void save_bmp(struct data_s data);
void	ft_draw_walls(struct data_s data);
void	plafond(data_t *img, data_t *data);
void	sol(data_t *img, data_t *data);
void	error_map(char **str);
void	ft_pars_fichier(struct data_s *data);
int rgb_hex(int red, int green, int blue, data_t *data);
char *ft_itoa_base(int nb, char *str);
void    move(int key, data_t *data);
int ft_quit(data_t *data);
void ft_error(char *str, data_t *data);
void ft_error2(char *str);
int checkmap(struct data_s data);
int	split(char *line, int *y, data_t *data, int nb);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strcpy(char *dst, const char *sr);
char	*ft_strjoin_free(char *s1, char *s2);
int	ft_strsub_bis(char *line, data_t *data);
void	rotate(int key, data_t *data, double rotspeed);
void	save_bmp(struct data_s data);
int	parse_s_p(char *line, data_t *data);
void	ft_free_map(int **map, data_t *data);
void	ft_free_m(char **map, data_t *data);
data_t *lmlx_new_image(void *mlx_ptr, void *win_ptr, int width , int height);
int	**change_map2(char **map, int **str, int count, int i);
int	**change_map(char **map, int count, data_t *data);
void	pos_perso(struct data_s *data);
void	tex_sprite(data_t *data);
void	ft_check_pars(char **str, data_t *data);




