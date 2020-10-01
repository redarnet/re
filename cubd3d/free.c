/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 14:44:11 by redarnet          #+#    #+#             */
/*   Updated: 2020/07/22 13:19:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    ft_free_map(int **map, data_t *data)
{
        int x;

        x = 1;
        while (x != data->size_free + 1)
        {
                if (map[x])
                        free(map[x]);
                x++;
        }
}

void    ft_free_m(char **map, data_t *data)
{
        int x;

        x = 0;
        while (x != data->size_free)
        {
                if (map[x])
                        free(map[x]);
                x++;
        }
	free(map);
}
