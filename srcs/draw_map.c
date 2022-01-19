/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 06:34:09 by gborne            #+#    #+#             */
/*   Updated: 2022/01/19 06:34:30 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_square(t_img object, int len, int heigh, int color)
{
	while (object.x < len)
	{
		my_mlx_pixel_put(&object, object.x, object.y, color);
		object.x++;
	}
	while (object.y < heigh)
	{
		my_mlx_pixel_put(&object, object.x, object.y, color);
		object.y++;
	}
	while (object.x > 0)
	{
		my_mlx_pixel_put(&object, object.x, object.y, color);
		object.x--;
	}
	while (object.y > 0)
	{
		my_mlx_pixel_put(&object, object.x, object.y, color);
		object.y--;
	}
}

void	draw_map(t_img object, char *map)
{
	int	i;
	int	x;
	int	y;

	i = -1;
	x = 0;
	y = 0;
	while (map[++i])
	{
		if (map[i] == '\n')
		{
			y++;
			x = 0;
		}
		else
			x++;
	}
	draw_square(object, x, y, 0x054362F);
}
