/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 13:37:36 by redarnet          #+#    #+#             */
/*   Updated: 2020/03/12 14:51:10 by redarnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void  ft_sprite22(struct data_s data, int color, double *ZBuffer, int *img)
{
        int h;
        int texHeight = 64;
        int texWidth = 64;
        int *spriteOrder;
        double spriteDistance[data.numsprite];
        int buffer[500][500];
        struct sprite_s *sprite;
        t_t text;
        h = data.y;
        text = textures(&data);
spriteOrder = (int*)malloc(sizeof(int) * data.numsprite + 1);

   spriteOrder =  sortSprites(data, spriteOrder, spriteDistance, 5);


        int w;
        w  = data.x;
        int i;
        i = 0;
for ( i = data.numsprite ; i >= 0  ; i--)
{
        double spriteX = data.sprite[spriteOrder[i]].posy - data.px;
        double spriteY = data.sprite[spriteOrder[i]].posx - data.py;
      double invDet = 1.0 / (data.planeX * data.dirY - data.dirX * data.planeY); 
      double transformX = invDet * (data.dirY * spriteX - data.dirX * spriteY);
      double transformY = invDet * (-data.planeY * spriteX + data.planeX * spriteY); //this is actually the depth inside the screen, that what Z is in 3D

      int spriteScreenX = (int)((w / 2) * (1 + transformX / transformY));

      int spriteHeight = abss((int)((h / (transformY)))) ; //using 'transformY' instead of the real distance prevents fisheye
      int drawStartY = -spriteHeight / 2 + h / 2 ;
      if(drawStartY < 0) drawStartY = 0;
      int drawEndY = spriteHeight / 2 + h / 2 ;
      if(drawEndY >= h) drawEndY = h - 1;
      int spriteWidth = abss((int)((h / (transformY)))) / 2;
      int drawStartX = -spriteWidth / 2 + spriteScreenX ;
      if(drawStartX < 0) drawStartX = 0;
      int drawEndX = spriteWidth / 2 + spriteScreenX;
      if(drawEndX >= w) drawEndX = w - 1;
      for(int stripe = drawStartX; stripe < drawEndX; stripe++)
      {
        int texX = (int)(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * texWidth / spriteWidth) / 256;
        if(transformY > 0 && stripe > 0 && stripe < w && transformY < ZBuffer[stripe])
        for(int y = drawStartY; y < drawEndY; y++) //for every pixel of the current stripe
        {
          int d = (y) * 256 - h * 128 + spriteHeight * 128; //256 and 128 factors to avoid floats
          int texY = ((d * texHeight) / spriteHeight) / 256;
          int  color2 = text.texture[4][0][texWidth * texY + texX]; //get current color from the texture

          if((color2 & 0x00FFFFFF) != 0)
                data.img_data[y*500 + stripe] = color2;
          if((color & 0x00FFFFFF) != 0) buffer[y][stripe] = color; //paint pixel if it isn't black, black is the invisible color
      }
        }
        }

}

void	ft_draw_walls(struct data_s data, int key)
{
	int pix;
       int texHeight = 64;
       int texWidth = 64;
        int texY;
      int zo;
        int color;
	  double *ZBuffer;
	  int buffer[500][500];
	double spriteDistance[data.numsprite];
	int *spriteOrder;

	int h;
	struct sprite_s *sprite;
	t_t text;
	text = textures(&data);

	ZBuffer = (double*)malloc(sizeof(double) * 500 + 1);
	h = data.y;
	plafond(&data);
	sol(&data);
	pix = 0;
	while (pix != data.x)
	{
		color = 0;

		algo(&data, pix, data.dirX, data.dirY);
	algo2(&data);
		
      while ( data.y2< data.drawEnd)
      {
	      zo = data.texPos;
         texY = zo ;
        data.texPos += data.step;
        color = text.texture[data.texNum][0][texHeight * texY + data.texX];
		data.img_data[data.y2*500 + pix] = color;
		data.buffer[data.y2][pix] = color;
	data.y2++;
	}
	  ZBuffer[pix] = data.perwall;
		pix++;
	}

	spriteOrder = (int*)malloc(sizeof(int) * data.numsprite + 1);
   spriteOrder =  sortSprites(data, spriteOrder, spriteDistance, 5);
   
	
 
  
	int w;
	w  = data.x;
	int i;
	i = 0;

for ( i = data.numsprite ; i >= 0  ; i--)
{
	double spriteX = data.sprite[spriteOrder[i]].posy - data.px;
	double spriteY = data.sprite[spriteOrder[i]].posx - data.py;
      double invDet = 1.0 / (data.planeX * data.dirY - data.dirX * data.planeY); 
      double transformX = invDet * (data.dirY * spriteX - data.dirX * spriteY);
      double transformY = invDet * (-data.planeY * spriteX + data.planeX * spriteY); //this is actually the depth inside the screen, that what Z is in 3D

      int spriteScreenX = (int)((w / 2) * (1 + transformX / transformY));

      int spriteHeight = abss((int)((h / (transformY)))) ; //using 'transformY' instead of the real distance prevents fisheye
      int drawStartY = -spriteHeight / 2 + h / 2 ;
      if(drawStartY < 0) drawStartY = 0;
      int drawEndY = spriteHeight / 2 + h / 2 ;
      if(drawEndY >= h) drawEndY = h - 1;
      int spriteWidth = abss((int)((h / (transformY)))) / 2;
      int drawStartX = -spriteWidth / 2 + spriteScreenX ;
      if(drawStartX < 0) drawStartX = 0;
      int drawEndX = spriteWidth / 2 + spriteScreenX;
      if(drawEndX >= w) drawEndX = w - 1;
      for(int stripe = drawStartX; stripe < drawEndX; stripe++)
      {
        int texX = (int)(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * texWidth / spriteWidth) / 256;
        if(transformY > 0 && stripe > 0 && stripe < w && transformY < ZBuffer[stripe])
        for(int y = drawStartY; y < drawEndY; y++) //for every pixel of the current stripe
        {
          int d = (y) * 256 - h * 128 + spriteHeight * 128; //256 and 128 factors to avoid floats
          int texY = ((d * texHeight) / spriteHeight) / 256;
          int  color2 = text.texture[4][0][texWidth * texY + texX]; //get current color from the texture

          if((color2 & 0x00FFFFFF) != 0) 
		data.img_data[y*500 + stripe] = color2;
      //    if((color & 0x00FFFFFF) != 0) buffer[y][stripe] = color; //paint pixel if it isn't black, black is the invisible color
      }
	}
	}
	
	
	
   ft_sprite22(data, color, ZBuffer, data.img_data);
   mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr,0 , 0);

	
}


