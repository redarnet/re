/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 12:55:43 by redarnet          #+#    #+#             */
/*   Updated: 2020/07/17 20:55:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int split(char *line, int *y)
{
	int nb;
	int  i;

	i = 2;
	nb = 0;
	while (line[i] == ' ')
		i++;
	while (line[i] >= '0' && line[i] <= '9')
	{
		nb = nb * 10 - '0' + line[i];
		i++;
	}
	i++;
	while (line[i] == ' ')
		i++;
	while (line[i] >= '0' && line[i] <= '9')
	{
		*y = *y * 10 -  '0' + line[i];
		i++;
	}
	return nb;
}

int 	parse_s_p(char *line)
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
	while(line[i] == ' ')
		i++;
	while (line[i] >= '0' &&line[i] <= '9')
	{
		red = red * 10 - '0' + line[i];
		i++;
	}
	ft_putnbr_fd(red, 1);
	i++;
	while (line[i] >= '0' &&line[i] <= '9')
	{
		green = green * 10 - '0' + line[i];
		i++;
	}
	i++;
	while (line[i] >= '0' &&line[i] <= '9')
	{
		blue = blue * 10 - '0' + line[i];
		i++;
	}
	x = rgb_hex(red, green, blue);
	return x;
}


char *ft_strsub(char *line)
{
	char *str;
	int i;
	int z;

	i  = 3;
	z = 0;
	while (line[i] == ' ')
		i++;

	str = malloc(sizeof(char) * ft_strlen(line) - i + 1);
	while (line[i + z] != '\0')
	{
		str[z] = line[i + z];
		z++;
	}
	str[z] = '\0';
	return str;
}

	
	
void   pars(data_t *data, char *line)
{
	if (line[0] == 'R')
		data->x = split(line, &data->y);
	else if (line[0] == 'N') 
		data->text_nord[0] =  ft_strsub(line);
	else if (line[0] == 'S') 
	{
		if (line[1] == '0') 
			;
		else
		data->text_nord[1] =  ft_strsub(line);
	}
	else if (line[0] == 'W') 
		data->text_nord[2] =  ft_strsub(line);
	else if (line[0] == 'E') 
		data->text_nord[3] =  ft_strsub(line);
	else if (line[0] == 'F')
		data->couleur_sol = parse_s_p(line);
	else if (line[0] == 'C')
		data->couleur_plafond = parse_s_p(line);
		;
	data->text_nord[4] =  "textures/barrel.xpm";

}

void	recu_line(data_t *data, int x, int fd)
{
	char *line;
	while (x != 6)
	{
		get_next_line(fd, &line);
		while (!line[0])
			get_next_line(fd, &line);
		pars(data, line);
		x = x + 1;
	}
}

void	ft_pars_fichier(struct data_s *data)
{
	char *line;
	char *tab;
	int fd;
	int x;

	x = 0;
	fd = open("element.cub", O_RDONLY);
	get_next_line(fd, &line);
	pars(data, line);
	recu_line(data, x, fd);
	tab =  malloc(1);
	tab[0] = '\0';
	while (get_next_line(fd, &line) == 1)
	{
		pars(data, line);
		tab = ft_strjoin(tab , line);
		free(line);
		tab = ft_strjoin(tab, "\n");
	}
	free(line);
	line = NULL;
	data->map = ft_split(tab, '\n');
	free(tab);
	tab =  NULL;
}
