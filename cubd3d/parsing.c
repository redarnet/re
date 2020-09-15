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
void	ft_double_start(char **str, char c)
{
	int i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i][0] == c)
		{
			i++;
			while (str[i] != 0)
			{
				if(str[i][0] == c)
					ft_error("bad syntaxee");
				i++;
			}
		}
		i++;
	}
}

int first_letter(char c, int count)
{	
	if ( c == 'N' || c == 'R' || c == 'S' || c == 'W' || c == 'E' 
		|| c == 'F' || c == 'C' ) 
		return 1;
	if (c == '1' && count < 8)
		ft_error("badsyntaxe");
	if (c == '1')
		return 1;
	return 0;
}

int	ft_syntaxe(char **str)
{
	int y;
	int i;
	int count;

	i = 0;
	count = 0;
	y = 0;
	while (str[y] !=  0)
	{
		while (str[y][i] == ' ')
		{
			while(str[y][i] == ' ')
				i++;
			if (first_letter(str[y][i], count))
				count++;
			y++;
		}
		i = 0;
		if (first_letter(str[y][i], count))
			count++;
		y++;
	}
	return count;
}

void ft_check_pars(char **str)
{
	ft_double_start(str, 'R');
	ft_double_start(str, 'W');
	ft_double_start(str, 'E');
	ft_double_start(str, 'C');
	ft_double_start(str, 'F');
	ft_syntaxe(str);
	

}

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
	i++;
	while (line[i] == ' ')
		i++;
	if (line[i] != '\0')
		ft_error("syntaxe config");
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
	if (line[i] != ',')
		ft_error("syntaxe couleur");
	i++;
	while (line[i] >= '0' &&line[i] <= '9')
	{
		green = green * 10 - '0' + line[i];
		i++;
	}
	if (line[i] != ',')
		ft_error("syntaxe couleur");
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
	if (line[0] == 'N')
		if (line[1] != 'O')
			ft_error("syntaxe configh");
	if (line[0] == 'S')
	{
		if (line[1] == ' ')
			i = 2;
		if (line[1] != 'O' && line[1] != ' ')
			ft_error("synetaxe configh");
	}
	if (line[0] == 'W')
		if (line[1] != 'E')
			ft_error("syntaxe configh");
	if (line[0] == 'E')
		if (line[1] != 'A')
			ft_error("syntaxe configh");
	while (line[i] == ' ')
		i++;

	str = malloc(sizeof(char) * ft_strlen(line) - i + 1);
	while (line[i + z] != '\0')
	{
		if (line[i + z] == ' ')
		{
			while (line[i + z] == ' ')
			i++;
			if (line[i + z] != '\0')
				ft_error("syntaxe error");
			str[z] = '\0';
			return str;
		}
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
		data->text_nord[3] =  ft_strsub(line);
	else if (line[0] == 'S') 
	{
		if (line[1] == 'O')
			data->text_nord[0] =  ft_strsub(line);
		else 
			data->text_nord[4] = ft_strsub(line);
	}
	else if (line[0] == 'W') 
		data->text_nord[1] =  ft_strsub(line);
	else if (line[0] == 'E') 
		data->text_nord[2] =  ft_strsub(line);
	else if (line[0] == 'F')
		data->couleur_sol = parse_s_p(line);
	else if (line[0] == 'C')
		data->couleur_plafond = parse_s_p(line);
}

char	*recu_line(data_t *data, int x, int fd, char *tab)
{
	char *line;
	while (x != 6)
	{
		get_next_line(fd, &line);
		while (!line[0])
			get_next_line(fd, &line);
		pars(data, line);
		x = x + 1;
		tab = ft_strjoin(tab , line);
		tab = ft_strjoin(tab, "\n");
	}
	return (tab);
}

void	ft_pars_fichier(struct data_s *data)
{
	char *line;
	char *tab;
	int fd;
	int x;

	x = 0;
	fd = open("element.cub", O_RDONLY);
	tab =  malloc(1);
	tab[0] = '\0';
	get_next_line(fd, &line);
	tab = ft_strjoin(tab , line);
	tab = ft_strjoin(tab, "\n");
	pars(data, line);
	tab = recu_line(data, x, fd, tab);
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
	ft_check_pars(data->map);
	free(tab);
	tab =  NULL;
}
