/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 15:10:56 by redarnet          #+#    #+#             */
/*   Updated: 2020/03/12 14:41:47 by redarnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int deal_key_map(int key, data_t *data)
{
//	remplir_blanc(*data);
//	plafond(data);

//	 afficher_mur(5, data);
	 
  double moveSpeed = 0.07;
  double rotSpeed = 0.06;

          if (key == key_w)
    {
      if(data->map2[(int)(data->px + data->dirX * moveSpeed)][(int)(data->py)] < 1) data->px += data->dirX * moveSpeed ;
      if(data->map2[(int)(data->px)][(int)(data->py + data->dirY * moveSpeed)] < 1){
           data->py += data->dirY * moveSpeed;
      }
    }
          if (key == key_s)
    {       
      if(data->map2[(int)(data->px - data->dirX * moveSpeed)][(int)(data->py)] < 1) data->px -= data->dirX * moveSpeed ;
      if(data->map2[(int)(data->px)][(int)(data->py - data->dirY * moveSpeed)] < 1) data->py -= data->dirY * moveSpeed ;
    }

  if (key == key_d)
    {
      double oldDirX = data->dirX;
      data->dirX = data->dirX * cos(-rotSpeed) - data->dirY * sin(-rotSpeed);
      data->dirY = oldDirX * sin(-rotSpeed) + data->dirY * cos(-rotSpeed);
      double oldPlaneX = data->planeX;
      data->planeX = data->planeX * cos(-rotSpeed) - data->planeY * sin(-rotSpeed);
      data->planeY = oldPlaneX * sin(-rotSpeed) + data->planeY * cos(-rotSpeed);
    }
  if (key == key_a)
    {
      double oldDirX = data->dirX;
      data->dirX = data->dirX * cos(rotSpeed) - data->dirY * sin(rotSpeed);
      data->dirY = oldDirX * sin(rotSpeed) + data->dirY * cos(rotSpeed);
      double oldPlaneX = data->planeX;
      data->planeX = data->planeX * cos(rotSpeed) - data->planeY * sin(rotSpeed);
      data->planeY = oldPlaneX * sin(rotSpeed) + data->planeY * cos(rotSpeed);
    }   
	ft_draw_walls(*data, key);
	return (0);
}
