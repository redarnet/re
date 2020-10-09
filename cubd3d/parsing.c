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

char	*ft_subtext(char *line, t_data *data)
{
	char	*str;
	int		i;
	int		z;

	i = ft_subtext2(line, data);
	if (!(str = malloc(sizeof(char) * (ft_strlen(line) - data->u + 1))))
		return (NULL);
	z = 0;
	while (line[i + z] != '\0')
	{
		if (line[i + z] == ' ')
		{
			while (line[i + z] == ' ')
				i++;
			if (line[i + z] != '\0')
				ft_error("syntaxe error", data);
			str[z] = '\0';
			return (str);
		}
		str[z] = line[i + z];
		z++;
	}
	str[z] = '\0';
	return (str);
}

void	pars(t_data *data, char *line)
{
	int nb;

	nb = 0;
	if (line[0] == 'R')
		data->x = split(line, &data->y, data, nb);
	else if (line[0] == 'N')
		data->text_nord[3] = ft_subtext(line, data);
	else if (line[0] == 'S')
	{
		if (line[1] == 'O')
			data->text_nord[0] = ft_subtext(line, data);
		else
			data->text_nord[4] = ft_subtext(line, data);
	}
	else if (line[0] == 'W')
		data->text_nord[1] = ft_subtext(line, data);
	else if (line[0] == 'E')
		data->text_nord[2] = ft_subtext(line, data);
	else if (line[0] == 'F')
		data->couleur_sol = parse_s_p(line, data);
	else if (line[0] == 'C')
		data->couleur_plafond = parse_s_p(line, data);
}

char	*ft_pars_fichier2(char *tab, char *line, t_data *data)
{
	char *str;

	str = tab;
	pars(data, line);
	tab = ft_strjoin(str, line);
	free(str);
	free(line);
	str = tab;
	tab = ft_strjoin(str, "\n");
	free(str);
	return (tab);
}

void	ft_pars_fichier(struct s_data *data, char *argv)
{
	char	*line;
	char	*tab;
	char	*str;
	int		fd;
	int		x;

	x = 0;
	str = NULL;
	if ((fd = open(argv, O_RDONLY)) == -1)
		ft_error2("wrong open");
	get_next_line(fd, &line);
	tab = ft_strjoin(str, line);
	free(str);
	str = tab;
	tab = ft_strjoin(str, "\n");
	free(str);
	pars(data, line);
	free(line);
	while (get_next_line(fd, &line) == 1)
		tab = ft_pars_fichier2(tab, line, data);
	data->map = ft_split((tab), '\n');
	ft_check_pars(data->map, data);
	free(tab);
	free(line);
}
