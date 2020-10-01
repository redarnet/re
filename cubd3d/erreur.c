/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erreur.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 12:42:07 by redarnet          #+#    #+#             */
/*   Updated: 2020/08/05 16:27:53 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_error(char *str, data_t *data)
{
	ft_putstr_fd(str, 1);
	ft_putstr_fd("Error\n", 1);
	ft_quit(data);
}

void	ft_error2(char *str)
{
	ft_putstr_fd(str, 1);
	ft_putstr_fd("Error\n", 1);
	exit(5);
}
