/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 06:22:03 by gborne            #+#    #+#             */
/*   Updated: 2022/01/22 18:02:23 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_s_map(t_map *map)
{
	map->x_max = 0;
	map->y_max = 0;
	map->coll = 0;
	map->exit = 0;
	map->error = NULL;
	map->temp_map = malloc(sizeof(char *));
	map->player.quantity = 0;
	map->player.count = 0;
	map->player.x = 0;
	map->player.y = 0;
	map->player.coll = 0;
	map->player.exit = 0;
}

void	init_player(t_map *map, int i)
{
	map->player.quantity++;
	map->player.x = i % map->x_max;
	map->player.y = map->y_max;
}

void	check_line(char *line, t_map *map)
{
	int	i;

	i = -1;
	while (line[++i] != '\0' && line[i] != '\n')
	{
		if (map->y_max == 0)
			map->x_max++;
		if ((map->y_max == 0 || i == 0 || i == map->x_max) && line[i] != '1')
			map->error = "Les bordures sont mal définies.";
		else if (line[i] == 'C')
			map->coll++;
		else if (line[i] == 'P')
			init_player(map, i);
		else if (line[i] == 'E')
			map->exit++;
		else if (!ft_strchr("1CPE0", line[i]))
			map->error = "Un character différent de '1CPE0' est présent dans la map.";
	}
	if (i != map->x_max)
		map->error = "Les bordures sont mal définies.";
	map->y_max++;
}

void	check_last(t_map *map)
{
	int i;
	int	x;
	int	y;

	i = -1;
	x = 0;
	y = 0;
	if (map->x_max < 1 || map->y_max < 1 || map->coll < 1 || map->exit != 1 || map->player.quantity != 1)
		map->error = "Une map doit contenir un joueur, une sortie et au moins un collectible.";
	while (map->temp_map[++i] != '\0' && y < map->y_max)
		if (map->temp_map[i] == '\n')
			y++;
	while (map->temp_map[i] != '\0' && map->temp_map[i] != '\n')
	{
		x++;
		if (x > map->x_max || map->temp_map[i] != '1')
			map->error = "Les bordures sont mal définies.";
		i++;
	}
}

void	construct_map(t_map *map)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	map->map = malloc(sizeof(char *) * (map->y_max + 1));
	while (map->temp_map[i] && y < map->y_max)
	{
		map->map[y] = malloc(sizeof(char) * (map->x_max + 1));
		while (x < map->x_max)
		{
			map->map[y][x] = map->temp_map[i];
			x++;
			i++;
		}
		map->map[y][x] = '\0';
		x = 0;
		y++;
		i++;
	}
	map->map[y] = NULL;
}

int	init_map(int argc, char *file, t_map *map)
{
	int		fd;
	char	*line;

	init_s_map(map);
	fd = open(file, O_RDONLY);
	if (fd < 1 || argc != 2)
	{
		map->error = "Entrez une unique map au format 'example.ber'.";
		return (0);
	}
	line = malloc(sizeof(char *));
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line != NULL)
		{
			check_line(line, map);
			map->temp_map = ft_strjoin(map->temp_map, line);
		}
	}
	close(fd);
	free(line);
	check_last(map);
	if (map->error)
		return (0);
	construct_map(map);
	return (1);
}
