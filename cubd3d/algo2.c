#include "cub3d.h"

void 	algo2(data_t *data)
{
	int lineHeight;
	int drawStart;
	double wallx;
	int texWidth = 64;
	int texHeight = 64;
	int h;
	
	h = data->y;
	lineHeight = (data->y / data->perwall);
        drawStart = -lineHeight / 2 + data->y / 2;
      if (drawStart < 0)
              drawStart = 0;
      data->drawEnd = lineHeight / 2 + data->y / 2;
      if (data->drawEnd >= data->y)
              data->drawEnd = data->y - 1;
      if (data->side == 0)
              wallx =  data->py + data->perwall * data->raydiry;
      else
              wallx= data->px + data->perwall * data->raydirx;
      wallx -= (int)wallx;
      data->texX = (wallx * (double)texWidth);
      if (data->side == 0 && data->raydirx > 0)
              data->texX = texWidth - data->texX - 1;
      if (data->side == 1 && data->raydiry < 0)
              data->texX = texWidth - data->texX - 1;

       data->step = 1.0 * texHeight / lineHeight;

      data->texPos = (drawStart - h / 2 + lineHeight / 2) * data->step;

           data->y2 = drawStart;

      data->texNum = data->map2[data->mapx][data->mapy];
     }

