/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 03:46:51 by gborne            #+#    #+#             */
/*   Updated: 2022/01/19 17:05:42 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	my_mlx_pixel_put(t_root *data, int x, int y, int color)
{
	char	*dst;

	dst = data->address + (y * data->line_len + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

unsigned int	my_mlx_get_pixel_color(int x, int y, void *sprite)
{
	char	*src;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	addr = mlx_get_data_addr(sprite, &bits_per_pixel, &line_length, &endian);
	src = addr + (y * line_length + x * (bits_per_pixel / 8));
	return (*(unsigned int *)src);
}
