/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_root.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 03:09:12 by gborne            #+#    #+#             */
/*   Updated: 2022/05/27 14:56:24 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static t_map	*init_s_map(t_map *map)
{
	map->x_max = 0;
	map->y_max = 0;
	map->coll = 0;
	map->exit = 0;
	map->player = 0;
	map->temp_map = malloc(sizeof(char *));
	map->temp_map[0] = '\0';
	return (map);
}

static t_player	*init_s_player(t_player *player)
{
	player->count = 0;
	player->x = 0;
	player->y = 0;
	player->coll = 0;
	player->exit = 0;
	return (player);
}

t_root	*init_root(t_root *root, t_map *map, t_player *s_player)
{
	root->mlx = NULL;
	root->win = NULL;
	root->s_map = init_s_map(map);
	root->player = init_s_player(s_player);
	root->error = NULL;
	root->map = NULL;
	return (root);
}
