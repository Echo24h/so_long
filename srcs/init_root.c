/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_root.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 03:46:51 by gborne            #+#    #+#             */
/*   Updated: 2022/01/21 12:33:34 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	*texture_load(t_root *root, char *path)
{
	int		width;
	int		height;
	void	*img;

	img = mlx_xpm_file_to_image(root->mlx, path, &width, &height);
	ft_printf("img : %p", img);
	if (img == 0)
		ft_printf("Les textures n'ont pas pu charger.");
	return (img);
}

void	texture_init(t_root *root)
{
	root->player = texture_load(root, "./img/enemy1.xpm");
	root->exit = texture_load(root, "./img/exit.xpm");
	root->coll = texture_load(root, "./img/collec.xpm");
	root->wall = texture_load(root, "./img/tree.xpm");
	root->ground = texture_load(root, "./img/floor.xpm");
	ft_printf("player : %p", root->exit);
}

void	init_root(t_root *root, t_map *map)
{
	root->mlx = mlx_init();
	root->win = mlx_new_window(root->mlx, map->x_max * SPRITE_X, map->y_max * SPRITE_Y, "So long!");
	root->img = mlx_new_image(root->mlx, map->x_max * SPRITE_X, \
		map->y_max * SPRITE_Y);
	root->address = mlx_get_data_addr(root->img, &root->bits_per_pixel, \
		&root->line_len, &root->endian);
	texture_init(root);
}
