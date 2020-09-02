/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 13:02:20 by redarnet          #+#    #+#             */
/*   Updated: 2020/08/05 17:04:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		diff(int x, int y)
{
	int z;

	if (x < y)
		z = 1;
	else
		z = -1;
	return (z);
}

void	line(struct data_s data, int x1, int y1, int x2, int y2, int couleur)
{
	int x;
	int y;
	int dx;
	int dy;
	int yincr;
	int xincr;
	int erreur;
	int i;

	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	xincr = diff(x1, x2);
	yincr = diff(y1, y2);
	x = x1;
	y = y1;
	if (dx > dy)
	{
		erreur = dx / 2;
		i = 0;
		while (i < dx)
		{
			x += xincr;
			erreur += dy;
			if (erreur > dx)
			{
				erreur -= dx;
				y += yincr;
			}
			data.img_data[y * 500 + x] = couleur;
			i++;
		}
	}
	else
	{
		erreur = dy / 2;
		i = 0;
		while (i < dy)
		{
			y += yincr;
			erreur += dx;
			if (erreur > dy)
			{
				erreur -= dy;
				x += xincr;
			}
			data.img_data[y * 500 + x] = couleur;
			i++;
		}
	}
	data.img_data[y1 * 500 + x1] = couleur;
	data.img_data[y1 * 500 + x2] = couleur;
}

void	plafond(struct data_s *data)
{
	int i;
	int y;

	i = 0;
	while (i != data->y)
	{
		line(*data, i, 250, i, 500, data->couleur_sol);
		i++;
	}
}

void	sol(struct data_s *data)
{
	int i;
	int y;

	i = 0;
	while (i != data->x)
	{
		line(*data, i, 0, i, 250, data->couleur_plafond);
		i++;
	}
}
