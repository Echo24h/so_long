/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 03:46:51 by gborne            #+#    #+#             */
/*   Updated: 2022/01/19 17:32:30 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_sprite(t_root *root, void *sprite, size_t x, size_t y)
{
	int	pixel_x;
	int	pixel_y;
	int	color;

	pixel_x = 0;
	pixel_y = 0;
	while (pixel_y < SPRITE_Y)
	{
		pixel_x = 0;
		while (pixel_x < SPRITE_X)
		{
			ft_printf("x:%d, y:%d, sprite: %p", pixel_x, pixel_x, sprite);
			color = my_mlx_get_pixel_color(pixel_x, pixel_y, sprite);
			if (!(color & (0xFF << 24)))
				my_mlx_pixel_put(root, (x * SPRITE_X) + pixel_x, (y * SPRITE_Y) + pixel_y, color);
			pixel_x++;
		}
		pixel_y++;
	}
}

void	generate_img(t_root *root, size_t x, size_t y, char c)
{
	ft_printf("\nsprite: %p", root->ground);
	ft_printf("\n%c\n", c);
	if (c == '1')
		put_sprite(root, root->wall, x, y);
	else if (c == '0')
		put_sprite(root, root->ground, x, y);
	else if (c == 'C')
		put_sprite(root, root->coll, x, y);
	else if (c == 'E')
		put_sprite(root, root->exit, x, y);
	else if (c == 'P')
		put_sprite(root, root->player, x, y);

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
	mlx_put_image_to_window(root->mlx, root->win, root->address, 0, 0);
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
