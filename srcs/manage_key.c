/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 06:32:35 by gborne            #+#    #+#             */
/*   Updated: 2022/04/28 17:37:41 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_win(t_root *root)
{
	int	y;

	y = -1;
	mlx_destroy_window(root->mlx, root->win);
	free(root->mlx);
	while (root->map[++y])
		free(root->map[y]);
	free(root->map);
	exit(0);
}

int	detect_cell(t_root *root, char cell)
{
	if (cell == '1' || (cell == 'E' && root->player->coll != root->s_map->coll))
		return (0);
	root->player->count++;
	ft_printf("Score : %d\n", root->player->count);
	if (cell == 'C')
		root->player->coll++;
	if (cell == 'E' && root->player->coll == root->s_map->coll)
	{
		ft_printf("!!!YOU HAVE WIN!!!\n");
		close_win(root);
	}
	return (1);
}

void	move_sprite(t_root *root, int y, int x)
{
	int		x_player;
	int		y_player;
	char	cell;

	x_player = root->player->x;
	y_player = root->player->y;
	cell = root->map[y_player + y][x_player + x];
	if (!detect_cell(root, cell))
		return ;
	root->map[y_player][x_player] = '0';
	root->map[y_player + y][x_player + x] = 'P';
	root->player->x += x;
	root->player->y += y;
	init_screen(root);
}

void	manage_move(t_root *root, int key)
{
	if (key == LEFT_KEY || key == A_KEY)
		move_sprite(root, 0, -1);
	else if (key == RIGHT_KEY || key == D_KEY)
		move_sprite(root, 0, 1);
	else if (key == UP_KEY || key == W_KEY)
		move_sprite(root, -1, 0);
	else if (key == DOWN_KEY || key == S_KEY)
		move_sprite(root, 1, 0);
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
