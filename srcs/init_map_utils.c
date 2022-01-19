/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 06:22:03 by gborne            #+#    #+#             */
/*   Updated: 2022/01/19 09:01:56 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_s_map(t_map *map)
{
	map->wight = 0;
	map->height = 0;
	map->collectible = 0;
	map->exit = 0;
	map->player = 0;
	map->error = NULL;
	map->map = NULL;
}
