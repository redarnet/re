/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 14:44:11 by redarnet          #+#    #+#             */
/*   Updated: 2020/07/22 13:19:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CUB3D_H
# define __CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <math.h>
# include "minilibx-linux/mlx.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# define KEY_FD 65363
# define KEY_FG 65361
# define KEY_A 97
# define KEY_S 115
# define KEY_W 119
# define KEY_D 100

typedef struct	s_t
{
	int		texture[6][64][64];
	int		i;
	int		x;
	char	*ptr;
	int		y;
	int		endian;
	void	*z;
}				t_t;

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

typedef struct	s_sprite
{
	double	posx;
	double	posy;
	double	spritex;
	double	spritey;
	double	transformx;
	double	transformy;
	int		spritescreenx;
	int		spriteheight;
	int		drawstarty;
	int		drawendy;
	int		spritewidth;
	int		drawstartx;
	int		drawendx;
	int		stripe;
	int		texx;
	int		texy;
	int		color2;

}				t_sprite;

typedef struct	s_data
{
	t_sprite	*sprite;
	double		zbuffer[500];
	t_t			text;
	double		texpos;
	void		*mlx_ptr;
	void		*win_ptr;
	char		**map;
	float		px;
	float		py;
	double		step;
	void		*img_ptr;
	float		dirx;
	float		diry;
	float		raydirx;
	float		raydiry;
	double		planex;
	double		planey;
	float		perwall;
	char		*text_nord[5];
	float		sidedirx;
	float		sidediry;
	float		deltadirx;
	float		deltadiry;
	int			texnum;
	int			walldir;
	int			texx;
	int			y2;
	int			x;
	int			y;
	int			**map2;
	int			couleur1;
	int			couleur2;
	int			couleur3;
	int			couleur_sol;
	int			couleur_plafond;
	int			green;
	int			red;
	int			texheight;
	int			texwidth;
	int			*img_data;
	int			side;
	int			mapx;
	int			mapy;
	int			drawend;
	int			bpp;
	int			numsprite;
	int			stepx;
	int			stepy;
	int			count;
	int			count2;
	int			size_free;
	int			size_l;
	int			u;

}				t_data;

void			textures(t_data *data);
int				deal_key_map(int key, t_data *data);
void			algo(t_data *data, int pix);
void			ft_algo(struct s_data data,
			int *img_data2, int texheight, double *zbuffer);
void			algo2(t_data *data);
void			ft_sprite(struct s_data data, int *img_data2);
double			abss(double a);
void			save_bmp(struct s_data data);
void			ft_draw_walls(struct s_data data);
void			plafond(t_data *img, t_data *data);
void			sol(t_data *img, t_data *data);
void			error_map(char **str);
void			ft_pars_fichier(struct s_data *data, char *argv);
int				rgb_hex(int red, int green, int blue, t_data *data);
char			*ft_itoa_base(int nb, char *str);
void			move(int key, t_data *data);
int				ft_quit(t_data *data);
void			ft_error(char *str, t_data *data);
void			ft_error2(char *str);
void			checkmap2(t_data *data);
int				start_map(struct s_data data);
int				split(char *line, int *y, t_data *data, int nb);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strcpy(char *dst, const char *sr);
char			*ft_strjoin_free(char *s1, char *s2);
int				ft_strsub_bis(char *line, t_data *data);
void			rotate(int key, t_data *data, double rotspeed);
void			save_bmp(struct s_data data);
int				parse_s_p(char *line, t_data *data);
void			ft_free_map(int **map, t_data *data);
void			ft_free_m(char **map);
t_data			*lmlx_new_image(void *mlx_ptr,
			void *win_ptr, int width, int height);
void			lmlx_destroy_image(t_data *img);
int				**change_map2(char **map, int **str, int count, int i);
int				**change_map(char **map, int count, t_data *data);
void			pos_perso(struct s_data *data);
void			tex_sprite(t_data *data);
void			ft_check_pars(char **str, t_data *data);
int				ft_subtext2(char *line, t_data *data);

#endif
