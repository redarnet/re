#include "cub3d.h"
int *sortSprites(struct data_s data, int *sprite_order, double *sprite_distance, int sprite_nb)
{
        int i;
        int tmp_order;
        double tmp_dist;

for (int i = 0; i < data.numsprite; i++)
{
sprite_order[i] = i;
      sprite_distance[i] = ((data.px - data.sprite[i].posy) * (data.px - data.sprite[i].posy) + (data.py - data.sprite[i].posx) * (data.py - data.sprite[i].posx)); //sqrt not taken, unneeded
    }
        i = 0;
        while (i < sprite_nb - 1)
        {
                if (sprite_distance[i] > sprite_distance[i + 1])
                {
                        tmp_dist = sprite_distance[i];
                        sprite_distance[i] = sprite_distance[i + 1];
                        sprite_distance[i + 1] = tmp_dist;
                        tmp_order = sprite_order[i];
                        sprite_order[i] = sprite_order[i + 1];
                        sprite_order[i + 1] = tmp_order;
                        i = -1;
                }
                i++;
        }
        return sprite_order;
}

double abss(double a)
{
        if (a < 0)
                a = -a;
        return a;
}


void  ft_sprite(struct data_s data, int color, double *ZBuffer, int *img)
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
        for(int y = drawStartY; y < drawEndY; y++) //for every pixel of the current stripe
        {
          int d = (y) * 256 - h * 128 + spriteHeight * 128; //256 and 128 factors to avoid floats
          int texY = ((d * texHeight) / spriteHeight) / 256;
          int  color2 = text.texture[4][0][texWidth * texY + texX]; //get current color from the texture

          if((color2 & 0x00FFFFFF) != 0) 
                data.img_data[y*500 + stripe] = color2;
          if((color & 0x00FFFFFF) != 0) data.buffer[y][stripe] = color; //paint pixel if it isn't black, black is the invisible color
      }
        }
      mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr,0 , 0);
     }
	
}

