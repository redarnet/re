/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 13:02:20 by redarnet          #+#    #+#             */
/*   Updated: 2020/03/12 14:08:16 by redarnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	line(struct data_s data, int x1, int y1, int x2, int y2, int couleur)
{
	int x,y;
  int Dx,Dy;
  int xincr,yincr;
  int erreur;
  int i;

  Dx = abs(x2-x1);
  Dy = abs(y2-y1);
  if(x1<x2)
    xincr = 1;
  else
    xincr = -1;
  if(y1<y2)
    yincr = 1;
  else
    yincr = -1;

  x = x1;
  y = y1;
  if(Dx>Dy)
    {
      erreur = Dx/2;
      for(i=0;i<Dx;i++)
        {
          x += xincr;
          erreur += Dy;
          if(erreur>Dx)
            {
              erreur -= Dx;
              y += yincr;
            }
	  data.img_data[y*500 +x ] = couleur;
        }
    }
  else
    {
      erreur = Dy/2;
      for(i=0;i<Dy;i++)
        {
          y += yincr;
          erreur += Dx;
          if(erreur>Dy)
            {
              erreur -= Dy;
              x += xincr;
            }
	  data.img_data[y*500 +x ] = couleur;
        }
    }
	  data.img_data[y1*500 +x1 ] = couleur;
	  data.img_data[y1*500 +x2 ] = couleur;
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
