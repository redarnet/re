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

void	plafond(t_data *img, t_data *data)
{
	int i;
	int y;

	i = 0;
	y = 0;
	while (i != data->x)
	{
		y = 0;
		while (y != data->y / 2)
		{
			img->img_data[y * data->x + i] = data->couleur_plafond;
			y++;
		}
		i++;
	}
}

void	sol(t_data *img, t_data *data)
{
	int i;
	int y;

	i = 0;
	y = data->x / 2;
	while (i != data->x)
	{
		y = data->y / 2;
		while (y != data->y)
		{
			img->img_data[y * data->x + i] = data->couleur_sol;
			y++;
		}
		i++;
	}
}
