/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 06:22:03 by gborne            #+#    #+#             */
/*   Updated: 2022/01/19 06:39:55 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_s_map(t_map *map)
{
	map->error = NULL;
	map->map = NULL;
	map->wight = 0;
	map->height = 0;
}

char	*check_map(int argc, char *file)
{
	int		fd;
	char	*line;

	if (argc != 2)
		return ("Veuillez entrer une map");
	fd = open(file, O_RDONLY);
	line = malloc(sizeof(char *));
	while (line != NULL)
	{
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	return (NULL);
}

int	init_map(int argc, char *file, t_map *map)
{
	int		fd;
	char	*line;
	char	*str;

	map->error = check_map(argc, file);
	if (map->error)
		return (0);
	fd = open(file, O_RDONLY);
	str = malloc(sizeof(char *));
	line = malloc(sizeof(char *));
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line != NULL)
			str = ft_strjoin(str, line);
	}
	ft_printf("%s", map);
	map->map = str;
	close(fd);
	free(line);
	return (1);
}
