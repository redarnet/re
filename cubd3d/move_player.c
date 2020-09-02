/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 14:35:05 by redarnet          #+#    #+#             */
/*   Updated: 2020/09/01 16:19:34 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_player(int nb, data_t *data)
{
	float tmpx;
	float tmpy;
	int tx;
	int ty;
	int x;
	int y;

	x = data->px;
	y = data->py;
//	data->map2[y][x] = 0;
	tmpx = data->px + 1*0.2;
	tmpy = data->py + 1 *0.2;
	tx = tmpx;
	ty = tmpy;
	if ((data->map2[ty][x]) == 0)
		data->py = tmpy;
	if ((data->map2[y][tx]) == 0)
		data->px = tmpx;
	x = data->px;
	y = data->py;
//	data->map2[y][x] = 'p' - 48;
}

void	rotate(int key, data_t *data)
{
	if ( key == key_a)
		data->angle += data->rotate;
	if ( key == key_d)
		data->angle -= data->rotate;
}
