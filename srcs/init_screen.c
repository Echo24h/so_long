/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 03:46:51 by gborne            #+#    #+#             */
/*   Updated: 2022/04/28 17:39:45 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	generate_img(t_root *root, int x, int y, char c)
{
	if (c == '1')
		mlx_put_image_to_window(root->mlx, root->win,
			root->img_wall, x * SPRITE_X, y * SPRITE_Y);
	else if (c == 'C')
		mlx_put_image_to_window(root->mlx, root->win,
			root->img_coll, x * SPRITE_X, y * SPRITE_Y);
	else if (c == 'E')
		mlx_put_image_to_window(root->mlx, root->win,
			root->img_exit, x * SPRITE_X, y * SPRITE_Y);
	else if (c == 'P')
		mlx_put_image_to_window(root->mlx, root->win,
			root->img_player, x * SPRITE_X, y * SPRITE_Y);
	else
		mlx_put_image_to_window(root->mlx, root->win,
			root->img_ground, x * SPRITE_X, y * SPRITE_Y);
}

int	init_screen(t_root *root)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (root->map[y])
	{
		while (root->map[y][x])
		{
			generate_img(root, x, y, root->map[y][x]);
			x++;
			i++;
		}
		x = 0;
		y++;
		i++;
	}
	return (1);
}
