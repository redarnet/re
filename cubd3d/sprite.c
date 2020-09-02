#include "cub3d.h"

int	*sortSprites(struct data_s data, int *sprite_order,
		double *sprite_distance, int sprite_nb)
{
	int		i;
	int		tmp_order;
	double	tmp_dist;

	i = 0;
	while (i < data.numsprite)
	{
		sprite_order[i] = i;
		sprite_distance[i] = ((data.px - data.sprite[i].posy) *
			(data.px - data.sprite[i].posy) + (data.py - data.sprite[i].posx)
			* (data.py - data.sprite[i].posx));
		i++;
	}
	i = 0;
	while (i < sprite_nb - 1)
	{
		if (sprite_distance[i] > sprite_distance[i + 1])
		{
			tmp_dist = sprite_distance[i];
			sprite_distance[i] = sprite_distance[i + 1];
			sprite_distance[i + 1] = tmp_dist;
			tmp_order = sprite_order[i];
			sprite_order[i] = sprite_order[i + 1];
			sprite_order[i + 1] = tmp_order;
			i = -1;
		}
		i++;
	}
	return (sprite_order);
}

double	abss(double a)
{
	if (a < 0)
		a = -a;
	return (a);
}

void	ft_sprite2(struct data_s data, struct sprite_s sprite,
		double *zbuffer, int *img_data2)
{
	int y;
	int d;
	int texheight;
	int texwidth;
	t_t text;

	texheight = 64;
	texwidth = 64;
	text = textures(&data);
	while (sprite.stripe < sprite.drawendx)
	{
		sprite.texx = (int)(256 * (sprite.stripe - (-sprite.spritewidth / 2 +
			sprite.spritescreenx)) * texwidth / sprite.spritewidth) / 256;
		y = sprite.drawstarty;
		if (sprite.transformy > 0 && sprite.stripe > 0 && 
			sprite.stripe < data.x && sprite.transformy < zbuffer[sprite.stripe])
		while (y < sprite.drawendy)
		{
			d = (y) * 256 - data.y * 128 + sprite.spriteheight * 128;
			sprite.texy = ((d * texheight) / sprite.spriteheight) / 256;
			sprite.color2 = text.texture[4][0][texwidth *
				sprite.texy + sprite.texx];
			if ((sprite.color2 & 0x00FFFFFF) != 0)
				img_data2[y * 500 + sprite.stripe] = sprite.color2;
			y++;
		}
		sprite.stripe++;
	}
}

void ft_sprite1(struct data_s data, struct sprite_s *sprite)
{
	sprite->spriteheight = abss((int)((data.y / (sprite->transformy))));
	sprite->drawstarty = -sprite->spriteheight / 2 + data.y / 2;
	if (sprite->drawstarty < 0)
		sprite->drawstarty = 0;
	sprite->drawendy = sprite->spriteheight / 2 + data.y / 2;
	if (sprite->drawendy >= data.y)
		sprite->drawendy = data.y - 1;
	sprite->spritewidth = abss((int)((data.y / (sprite->transformy)))) / 2;
	sprite->drawstartx = -sprite->spritewidth / 2 + sprite->spritescreenx;
	if (sprite->drawstartx < 0)
		sprite->drawstartx = 0;
	sprite->drawendx = sprite->spritewidth / 2 + sprite->spritescreenx;
	if (sprite->drawendx >= data.x)
		sprite->drawendx = data.x - 1;
	sprite->stripe = sprite->drawstartx;
}

void	ft_sprite(struct data_s data, double *zbuffer, int *img_data2)
{
	int	i;
	int	*spriteorder;
	struct sprite_s	sprite;
	double		spritedistance[data.numsprite];

	spriteorder = (int*)malloc(sizeof(int) * data.numsprite + 1);
	spriteorder = sortSprites(data, spriteorder, spritedistance, 5);
	i = data.numsprite;
	while (i >= 0)
	{
		sprite.spritex = data.sprite[spriteorder[i]].posy - data.px;
		sprite.spritey = data.sprite[spriteorder[i]].posx - data.py;
		sprite.invdet = 1.0 / (data.planeX *
				data.dirY - data.dirX * data.planeY);
		sprite.transformx = sprite.invdet *
			(data.dirY * sprite.spritex - data.dirX * sprite.spritey);
		sprite.transformy = sprite.invdet *
			(-data.planeY * sprite.spritex + data.planeX * sprite.spritey);
		sprite.spritescreenx = (int)((data.x / 2) *
				(1 + sprite.transformx / sprite.transformy));
		ft_sprite1(data, &sprite);
		ft_sprite2(data, sprite, zbuffer, img_data2);
		i--;
	}
}

