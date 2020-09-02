#include "cub3d.h"

double	algo2bis(data_t *data)
{
	double wallx;

	if (data->side == 0)
		wallx = data->py + data->perwall * data->raydiry;
	else
		wallx = data->px + data->perwall * data->raydirx;
	return (wallx);
}

void	algo2(data_t *data)
{
	int		lineheight;
	int		drawstart;
	int		tex;
	double	wallx;

	tex = 64;
	lineheight = (data->y / data->perwall);
	drawstart = -lineheight / 2 + data->y / 2;
	if (drawstart < 0)
		drawstart = 0;
	data->drawEnd = lineheight / 2 + data->y / 2;
	if (data->drawEnd >= data->y)
		data->drawEnd = data->y - 1;
	wallx = algo2bis(data);
	wallx -= (int)wallx;
	data->texX = (wallx * (double)tex);
	if (data->side == 0 && data->raydirx > 0)
		data->texX = tex - data->texX - 1;
	if (data->side == 1 && data->raydiry < 0)
		data->texX = tex - data->texX - 1;
	data->step = 1.0 * tex / lineheight;
	data->texPos = (drawstart - data->y / 2 + lineheight / 2) * data->step;
	data->y2 = drawstart;
	data->texNum = data->map2[data->mapx][data->mapy];
}
