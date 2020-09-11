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

void	plafond(struct data_s *data)
{
        int i;
        int y;

        i = 0;
	y = 0;
        while (i != data->y)
        {
        	y = 0;
                while (y != data->x / 2)
                {
			data->img_data[y * 500 + i] = data->couleur_plafond;
                        y++;
                }
                i++;
        }
}

void	sol(struct data_s *data)
{
        int i;
        int y;

        i = 0;
        y = data->x/2;
        while (i != data->y)
        {
        	y = data->x/2;
                while (y != data->x)
                {
			data->img_data[y * 500 + i] = data->couleur_sol;
                        y++;
                }
                i++;
        }
}
