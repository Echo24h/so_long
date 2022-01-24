/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 06:32:35 by gborne            #+#    #+#             */
/*   Updated: 2022/01/22 18:24:53 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_win(t_root *root)
{
	mlx_destroy_window(root->mlx, root->win);
	free(root->mlx);
	exit(0);
}

void	move_sprite(char *player, char *cell)
{
	char	*temp;

	temp = cell;
	cell = player;
	player = temp;
	ft_printf("coucou");
}

void	manage_move(t_root *root, int key)
{
	size_t	x;
	size_t	y;

	x = root->map->player.x;
	y = root->map->player.y;

	if (key == LEFT_KEY)
		move_sprite(&root->map->map[y][x], &root->map->map[y][x - 1]);
	/*else if (key == RIGHT_KEY)
		move_sprite(root, y, x);
	else if (key == UP_KEY)
		move_sprite(root, y, x);
	else if (key == DOWN_KEY)
		move_sprite(root, y, x);*/
	init_screen(root, root->map);
}

int	manage_key(int key, t_root *root)
{
	if (key == LEFT_KEY || key == RIGHT_KEY || key == UP_KEY || key == DOWN_KEY
		|| key == A_KEY || key == W_KEY || key == S_KEY || key == D_KEY)
		manage_move(root, key);
	else if (key == ESC)
		close_win(root);
	return (1);
}
