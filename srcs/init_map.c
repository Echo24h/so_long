/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 06:22:03 by gborne            #+#    #+#             */
/*   Updated: 2022/01/19 09:16:18 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_line(char *line, t_map *map)
{
	int	i;

	i = -1;
	while (line[++i] != '\0' && line[i] != '\n')
	{
		if (line[i] == 'C')
			map->collectible++;
		else if (line[i] == 'P')
			map->player++;
		else if (line[i] == 'E')
			map->exit++;
	}
	ft_printf("check line : %s", line);
	map->height = 0;
}

char	*check_map(int argc, int fd, t_map *map)
{
	int		i;
	char	*line;

	i = 0;
	if (argc != 2)
		return ("Veuillez entrer une map");
	line = malloc(sizeof(char *));
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line != NULL)
			check_line(line, map);
	}
	free(line);
	return (NULL);
}

int	init_map(int argc, char *file, t_map *map)
{
	int		fd;
	char	*line;
	char	*str;

	init_s_map(map);
	fd = open(file, O_RDONLY);
	map->error = check_map(argc, fd, map);
	close(fd);
	if (map->error)
		return (0);
	fd = open(file, O_RDONLY);
	line = malloc(sizeof(char *));
	str = malloc(sizeof(char *));
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line != NULL)
			str = ft_strjoin(str, line);
	}
	map->map = str;
	close(fd);
	free(line);
	ft_printf("\n%s\n", map->map);
	ft_printf("Collectible : %d\nPlayer : %d\nExit : %d\n",
				map->collectible, map->player, map->exit);
	return (1);
}
