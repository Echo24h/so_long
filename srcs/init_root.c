/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_root.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 03:09:12 by gborne            #+#    #+#             */
/*   Updated: 2022/04/28 17:38:48 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_map	*init_s_map(t_map *map)
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

t_player	*init_s_player(t_player *player)
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
	root->s_map = init_s_map(map);
	root->player = init_s_player(s_player);
	root->error = NULL;
	return (root);
}

void	init_player(t_root *root, int i)
{
	root->s_map->player++;
	root->player->x = i % root->s_map->x_max;
	root->player->y = root->s_map->y_max;
}
