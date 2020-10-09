/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 14:44:11 by redarnet          #+#    #+#             */
/*   Updated: 2020/07/22 13:19:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		*sortsprites2(int *sprite_order, double *sprite_distance, int sprite_nb)
{
	int		i;
	int		tmp_order;
	double	tmp_dist;

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

int		*sortsprites(struct s_data data, int *sprite_order,
	int sprite_nb)
{
	int			i;
	double		sprite_distance[data.numsprite];

	i = 0;
	while (i < data.numsprite)
	{
		sprite_order[i] = i;
		sprite_distance[i] = ((data.px - data.sprite[i].posy) *
		(data.px - data.sprite[i].posy) + (data.py - data.sprite[i].posx)
				* (data.py - data.sprite[i].posx));
		i++;
	}
	sprite_order = sortsprites2(sprite_order, sprite_distance, sprite_nb);
	return (sprite_order);
}

void	ft_sprite2(struct s_data data, struct s_sprite sprite, int *img_data2)
{
	int y;
	int d;

	data.texheight = 64;
	data.texwidth = 64;
	while (sprite.stripe < sprite.drawendx)
	{
		sprite.texx = (int)(256 * (sprite.stripe - (-sprite.spritewidth / 2 +
		sprite.spritescreenx)) * data.texwidth / sprite.spritewidth) / 256;
		y = sprite.drawstarty;
		if (sprite.transformy > 0 && sprite.stripe > 0 && sprite.stripe
				< data.x && sprite.transformy < data.zbuffer[sprite.stripe])
			while (y < sprite.drawendy)
			{
				d = (y) * 256 - data.y * 128 + sprite.spriteheight * 128;
				sprite.texy = ((d * data.texheight) /
					sprite.spriteheight) / 256;
				sprite.color2 = data.text.texture[4][0][data.texwidth *
					sprite.texy + sprite.texx];
				if ((sprite.color2 & 0x00FFFFFF) != 0)
					img_data2[y * data.x + sprite.stripe] = sprite.color2;
				y++;
			}
		sprite.stripe++;
	}
}

void	ft_sprite1(struct s_data data, struct s_sprite *sprite)
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

void	ft_sprite(struct s_data data, int *img_data2)
{
	int				i;
	int				*spriteorder;
	struct s_sprite	sprite;

	spriteorder = (int*)malloc(sizeof(int) * data.numsprite);
	spriteorder = sortsprites(data, spriteorder,
		data.numsprite);
	i = data.numsprite - 1;
	while (i >= 0)
	{
		sprite.spritex = data.sprite[spriteorder[i]].posy - data.px;
		sprite.spritey = data.sprite[spriteorder[i]].posx - data.py;
		sprite.transformx = 1.0 / (data.planex *
				data.diry - data.dirx * data.planey) *
			(data.diry * sprite.spritex - data.dirx * sprite.spritey);
		sprite.transformy = 1.0 / (data.planex *
				data.diry - data.dirx * data.planey) *
			(-data.planey * sprite.spritex + data.planex * sprite.spritey);
		sprite.spritescreenx = (int)((data.x / 2) *
				(1 + sprite.transformx / sprite.transformy));
		ft_sprite1(data, &sprite);
		ft_sprite2(data, sprite, img_data2);
		i--;
	}
	free(spriteorder);
}
