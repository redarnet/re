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

int	ft_atoi2(char *str)
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

char	*ft_strcat(char *s1,const  char *s2)
{
	int i;
	int j;

	i = 0;
	while (s1[i] != '\0')
		i++;
	j = 0;
	while (s2[j] !=  '\0')
	{
		s1[i + j] = s2[j];
		j++;
	}
	s1[i + j] = '\0';
	return s1;
}
char	*ft_strcpy(char *dst, const char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char *ft_strjoin_free(char *s1, char *s2)
{
	char *str;

	if (!s2 || !s2)
		return (NULL);
	str = malloc(sizeof(ft_strlen(s1) + ft_strlen(s2)));
	str = ft_strcpy(str, s1);
	str = ft_strcat(str, s2);
	free(s1);
	free(s2);
	return str;
}

int	rgb_hex(int red, int green, int blue)
{
	char	*red2;
	char	*green2;
	char	*blue2;
	char	*end;
	char *swap;
	int		x;

	if (red > 255 || blue > 255 || green > 255)
		ft_error("couleur range");
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
	x = ft_atoi_base(end, "0123456789ABCDEF");
	free(end);
	return (x);
}
