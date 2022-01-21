/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 03:46:51 by gborne            #+#    #+#             */
/*   Updated: 2022/01/21 12:31:51 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	generate_img(t_root *root, size_t x, size_t y, char c)
{
	if (c == '1')
		mlx_put_image_to_window(root->mlx, root->win, root->wall, x * SPRITE_X, y * SPRITE_Y);
	else if (c == 'C')
		mlx_put_image_to_window(root->mlx, root->win, root->coll, x * SPRITE_X, y * SPRITE_Y);
	else if (c == 'E')
		mlx_put_image_to_window(root->mlx, root->win, root->exit, x * SPRITE_X, y * SPRITE_Y);
	else if (c == 'P')
		mlx_put_image_to_window(root->mlx, root->win, root->player, x * SPRITE_X, y * SPRITE_Y);
	else
		mlx_put_image_to_window(root->mlx, root->win, root->ground, x * SPRITE_X, y * SPRITE_Y);
}

int	init_screen(t_root *root, t_map *map)
{
	size_t	i;
	size_t	x;
	size_t	y;

	i = 0;
	x = 0;
	y = 0;
	while (map->map[i] && y < map->y_max)
	{
		while (x < map->x_max)
		{
			generate_img(root, x, y, map->map[i]);
			x++;
			i++;
		}
		x = 0;
		y++;
		i += 2;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_root	root;
	t_map	map;

	if(!init_map(argc, argv[1], &map))
		return (ft_printf("%s\n", map.error));
	init_root(&root, &map);

	ft_printf("\n%s\n", map.map);
	ft_printf("Collectible : %d\nPlayer : %d\nExit : %d\nx_max = %d, y_max = %d\n",
				map.coll, map.player, map.exit, map.x_max, map.y_max);

	init_screen(&root, &map);
	mlx_hook(root.win, 2, 1L<<0, &close_win, &root);
	mlx_loop(root.mlx);
	free(map.map);
	return (0);
}
