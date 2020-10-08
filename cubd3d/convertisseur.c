/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertisseur.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 16:54:39 by redarnet          #+#    #+#             */
/*   Updated: 2020/08/05 16:21:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_atoi2(char *str)
{
	int x;
	int i;

	i = 0;
	x = 0;
	while (str[i] != '\0')
	{
		x = x * 10 + str[i] - 48;
		i++;
	}
	return (x);
}


int		rgb_hex(int red, int green, int blue, data_t *data)
{
	char	*red2;
	char	*green2;
	char	*blue2;
	char	*end;
	char	*swap;

	if (red > 255 || blue > 255 || green > 255)
		ft_error("couleur range", data);
	red2 = ft_itoa_base(red, "0123456789ABCDEF");
	green2 = ft_itoa_base(green, "0123456789ABCDEF");
	blue2 = ft_itoa_base(blue, "0123456789ABCDEF");
	swap = "0";
	if (ft_strlen(red2) == 1)
		red2 = ft_strjoin(swap, red2);
	if (ft_strlen(green2) == 1)
		green2 = ft_strjoin(swap, green2);
	if (ft_strlen(blue2) == 1)
		blue2 = ft_strjoin(swap, blue2);
	end = ft_strjoin_free(red2, green2);
	end = ft_strjoin_free(end, blue2);
	data->couleur1 = ft_atoi_base(end, "0123456789ABCDEF");
	free(end);
	return (data->couleur1);
}

int     parse_s_p(char *line, data_t *data)
{
        int i;
        int red;
        int green;
        int blue;
        int x;

        red = 0;
        green = 0;
        blue = 0;
        i = 1;
        while (line[i] == ' ')
                i++;
        while (line[i] >= '0' && line[i] <= '9')
        {
                red = red * 10 - '0' + line[i];
                i++;
        }
        if (line[i] != ',')
                ft_error("syntaxe couleur", data);
        i++;
        while (line[i] >= '0' && line[i] <= '9')
        {
                green = green * 10 - '0' + line[i];
                i++;
        }
        if (line[i] != ',')
                ft_error("syntaxe couleur", data);
        i++;
        while (line[i] >= '0' && line[i] <= '9')
        {
                blue = blue * 10 - '0' + line[i];
                i++;
        }
        x = rgb_hex(red, green, blue, data);
        return (x);
}
