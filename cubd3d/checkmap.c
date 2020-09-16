#include "cub3d.h"

void	ft_check(data_t *data, char **str, char c, int x, int y, int o)
{
	int x1;
	int y1;
	if (c != 'N' && c != 'S' && c != 'E' && c != 'O'
		&& c != '1' && c != ' ' && c != '0' && c != '\0')
	{
		ft_putchar_fd(c, 1);
		ft_error("eerreur map");
	}
	if (c == 'N' || c == 'S' || c == 'E' || c == 'O')
	{
		if (data->count > 0)
		ft_error("erreur map");
		data->count = 1;
	}
	x1 = x;
	y1 = y;
	if (c == '0')
	{
		while  (str[y1][x1] != '\0') 
		{
			x1++;
			if (str[y1][x1] == '1')
				break;
			if (str[y1][x1] == ' ' || str[y1][x1 + 1] == '\0')
				ft_error("erreur mmmap");
		}
	}
	
	x1 = x;
	y1 = y;
	if (c == '0')
	{
		while  (str[y1] != 0) 
		{
			if (str[y1][x1] == '1')
				break;
			if (str[y1][x1] == ' ' || str[y1 + 1] == 0)
				ft_error("erreur mmmap");
			y1++;
		}
	}
	x1 = x;
	y1 = y;
	if (c == '0')
	{
		while  (y1 != o + 1) 
		{
			y1--;
			if (str[y1][x1] == '1')
				break;
			if (str[y1][x1] == ' ' || y1 < o)
			{
				ft_putnbr_fd(y1, 1);
				ft_putnbr_fd(x1, 1);
				ft_error("erreur ap");
			}
		}
	}
	
}

void	checkmap(struct data_s data, char **str)
{
	int x;
        int y;
	int o;

	data.count = 0;
        x = 0;
        y = 0;
	o = 0;
        while (str[y] != 0)
        {
                x = 0;
                while (str[y][x] != '\0')
                {
			if ((str[y][0] != 'R') && ( str[y][0] != 'F') && (str[y][0] != 'C'))
				if (str[y][x] == '1' && o == 0)
				{
				o = y;
				}
                        x++;
                }
                y++;
        }
	y = o;
        while (str[y] != 0)
        {
                x = 0;
                while (str[y][x] != '\0')
                {
			ft_putchar_fd(str[y][x], 1);
                        x++;
                }
		ft_putchar_fd('\n', 1);
                y++;
        }
	y = o;
        while (str[y] != 0)
        {
                x = 0;
                while (str[y][x] != '\0')
                {
			ft_check(&data, str, str[y][x], x, y, o);
                        x++;
                }
                y++;
        }

}

