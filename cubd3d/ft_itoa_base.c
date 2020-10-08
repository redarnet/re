/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 17:27:24 by redarnet          #+#    #+#             */
/*   Updated: 2020/02/08 17:29:34 by redarnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int             ft_subtext2(char *line, data_t *data)
{
        int i;
        int z;

        i = ft_strsub_bis(line, data);
        z = 0;
        data->u = i;
        while (line[i + z] != '\0')
        {
                if (line[i + z] == ' ')
                        data->u++;
                z++;
        }
        while (line[i] == ' ')
                i++;
        return (i);
}

int		taille_malloc(int nbr, char *base)
{
	int len;

	len = ft_strlen(base);
	if (nbr >= 0 && nbr < len)
		return (1);
	else if (nbr < 0)
		return (taille_malloc(-nbr, base) + 1);
	else
		return (taille_malloc((nbr / len), base)
				+ taille_malloc(nbr % len, base));
}

char	*remplir(int nb, char *base, char *str, int i)
{
	int len;

	len = ft_strlen(base);
	str[i] = '\0';
	i--;
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb >= len)
	{
		str[i] = base[nb % len];
		nb = nb / len;
		i--;
	}
	str[i] = base[nb];
	return (str);
}

char	*ft_itoa_base(int n, char *base)
{
	char	*str;
	int		i;

	i = 0;
	if (n < 0)
		return (NULL);
	else
	{
		i = taille_malloc(n, base);
		if ((str = malloc(sizeof(char) * i + 1)) == NULL)
			return (0);
		str = remplir(n, base, str, i);
	}
	return (str);
}
