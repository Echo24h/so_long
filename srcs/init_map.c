/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 06:22:03 by gborne            #+#    #+#             */
/*   Updated: 2022/05/27 14:50:39 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	init_player(t_root *root, int i)
{
	root->s_map->player++;
	root->player->x = i % root->s_map->x_max;
	root->player->y = root->s_map->y_max;
}

static void	check_line(t_root *root, char *line)
{
	int	i;

	i = -1;
	while (line[++i] != '\0' && line[i] != '\n')
	{
		if (root->s_map->y_max == 0)
			root->s_map->x_max++;
		if ((root->s_map->y_max == 0 || i == 0
				|| i == root->s_map->x_max) && line[i] != '1')
			root->error = "Error\nWrong border.";
		else if (line[i] == 'C')
			root->s_map->coll++;
		else if (line[i] == 'P')
			init_player(root, i);
		else if (line[i] == 'E')
			root->s_map->exit++;
		else if (!ft_strchr("1CPE0", line[i]))
			root->error = "Error\nWrong character is on map.";
	}
	if (i != root->s_map->x_max)
		root->error = "Error\nWrong border.";
	root->s_map->y_max++;
}

static void	check_last(t_root *root)
{
	int	i;
	int	x;
	int	y;

	i = -1;
	x = 0;
	y = 0;
	if (root->s_map->x_max < 1
		|| root->s_map->y_max < 1 || root->s_map->coll < 1
		|| root->s_map->exit < 1 || root->s_map->player != 1)
		root->error = "Error\nWrong player, collectible, or border in map.";
	while (root->s_map->temp_map[++i] != '\0' && y + 1 < root->s_map->y_max)
	{
		if (root->s_map->temp_map[i] == '\n')
			y++;
		else if (root->s_map->temp_map[i + 1] == '\n'
			&& root->s_map->temp_map[i] != '1')
			root->error = "Error\nWrong border.";
	}
	while (root->s_map->temp_map[i] != '\0' && root->s_map->temp_map[i] != '\n')
	{
		if (++x > root->s_map->x_max || root->s_map->temp_map[i] != '1')
			root->error = "Error\nWrong border.";
		i++;
	}
}

static void	construct_map(t_root *root)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	root->map = malloc(sizeof(char *) * (root->s_map->y_max + 1));
	while (y < root->s_map->y_max)
	{
		root->map[y] = malloc(sizeof(char) * (root->s_map->x_max + 1));
		while (x < root->s_map->x_max)
		{
			root->map[y][x] = root->s_map->temp_map[i];
			x++;
			i++;
		}
		root->map[y][x] = '\0';
		x = 0;
		y++;
		i++;
	}
	root->map[y] = NULL;
}

int	init_map(int argc, char *file, t_root *root)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 1 || argc != 2)
	{
		root->error = "Error\nUse: ./so_long 'example.ber'.";
		return (0);
	}
	line = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		check_line(root, line);
		root->s_map->temp_map = ft_strjoin2(root->s_map->temp_map, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	check_last(root);
	if (root->error)
		return (0);
	construct_map(root);
	free(root->s_map->temp_map);
	return (1);
}
