/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 03:46:51 by gborne            #+#    #+#             */
/*   Updated: 2022/04/28 17:57:42 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	*get_img_sprite(t_root *root, char *path)
{
	int		width;
	int		height;
	void	*img;

	img = mlx_xpm_file_to_image(root->mlx, path, &width, &height);
	if (img == 0)
		ft_printf("Wrong sprite.");
	return (img);
}

void	init_sprite(t_root *root)
{
	root->img_player = get_img_sprite(root, "./img/sprite2.xpm");
	root->img_exit = get_img_sprite(root, "./img/exit.xpm");
	root->img_coll = get_img_sprite(root, "./img/collec.xpm");
	root->img_wall = get_img_sprite(root, "./img/tree.xpm");
	root->img_ground = get_img_sprite(root, "./img/floor.xpm");
}

void	init_img(t_root *root)
{
	root->mlx = mlx_init();
	root->win = mlx_new_window(root->mlx, root->s_map->x_max * SPRITE_X, \
		root->s_map->y_max * SPRITE_Y, "So long!");
	root->img = mlx_new_image(root->mlx, root->s_map->x_max * SPRITE_X, \
		root->s_map->y_max * SPRITE_Y);
	root->address = mlx_get_data_addr(root->img, &root->bits_per_pixel, \
		&root->line_len, &root->endian);
	init_sprite(root);
}
