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
	int size_l;
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
	int y;
	int d;
	int texy;
	int color2;

}	sprite_t;


typedef struct data_s
{
	sprite_t *sprite;
	//	struct sprite_s;
	int buffer[500][500];
	double ZBuffer[500];
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
	int posy;
	int posx;
	float angle;
	float rotate;
	float speed;
	int cmpx;
	int cmpy;
	int couleur_sol;
	int couleur_plafond;
	int green;
	int red;
	int blue;
	double step;
	int cmpr;
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
	int *d_ad;
	int sl;
	int sreenshot;
	int count;

}		data_t;

t_t textures(data_t *data);
int deal_key_map(int key, data_t *data);
void	algo(data_t *data, int pix, double dirX, double dirY);
void    ft_algo(struct data_s data, int *img_data2 , int texheight, double *zbuffer); 
void	algo2(data_t *data);
int	afficher_mur(int key,data_t *data);
void	ft_sprite(struct data_s data, double *ZBuffer, int *img_data2, struct t_s text);
void	remplir_blanc(struct data_s data);
void	move_player(int nb, data_t *data);
double abss(double a);
void save_bmp(struct data_s data);
//int *sortSprites(struct data_s data, int *sprite_order, double *sprite_distance, int sprite_nb);
void	rotate(int key, data_t *data);
void	ft_affiche_map(data_t *data);
int	affiche_bousole(int key, data_t *data);
void	line(struct data_s data, int x1, int y1, int x2, int y2, int couleur);
void	ft_draw_walls(struct data_s data, int key);
void	plafond(struct data_s *data);
void	sol(struct data_s *data);
void	error_map(char **str);
void	ft_pars_fichier(struct data_s *data);
int rgb_hex(int red, int green, int blue);
char *ft_itoa_base(int nb, char *str);
void	plafond(struct data_s *data);
void	sol(struct data_s *data);
void    move(int key, data_t *data);
int ft_quit(data_t *data);
void ft_error(char *str);
void checkmap(struct data_s data, char **str);

