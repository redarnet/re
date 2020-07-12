/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertisseur.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 16:54:39 by redarnet          #+#    #+#             */
/*   Updated: 2020/03/02 14:52:56 by redarnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ft_atoi2(char *str)
{
	int x;
	int i;

	i= 0;
	x= 0;
	while (str[i] != '\0')
	{
		x = x * 10 + str[i] - 48;
		i++;
	}
	return x;
}
int  rgb_hex(int red, int green, int blue)
{
	char *red2;
	char *green2;
	char *blue2;
	char *end;
	int x;

	red2 = ft_itoa_base(red, "0123456789ABCDEF");
	green2 = ft_itoa_base(green, "0123456789ABCDEF");
	blue2 = ft_itoa_base(blue, "0123456789ABCDEF");
	if (ft_strlen(red2) == 1)
		red2 = ft_strjoin("0", blue2);
	if (ft_strlen(green2) == 1)
		green2 = ft_strjoin("0", blue2);
	if (ft_strlen(blue2) == 1)
		blue2 = ft_strjoin("0", blue2);
	end = ft_strjoin(red2 , green2);
	end = ft_strjoin(end , blue2);
	x =  ft_atoi_base(end, "0123456789ABCDEF");
	return x;
}

