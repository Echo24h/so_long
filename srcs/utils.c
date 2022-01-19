/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 06:32:35 by gborne            #+#    #+#             */
/*   Updated: 2022/01/19 13:43:41 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_win(int key, t_root *vars)
{
	ft_printf("Key de la touche : %d", key);
	mlx_destroy_window(vars->mlx, vars->win);
	free(vars->mlx);
	exit(0);
}
