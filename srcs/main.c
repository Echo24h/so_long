/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 03:46:51 by gborne            #+#    #+#             */
/*   Updated: 2022/01/19 06:34:01 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_win	vars;
	t_img	img;
	t_map	map;

	if(!init_map(argc, argv[1], &map))
		return (ft_puterror(map.error));
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	img.img = mlx_new_image(vars.mlx, 100, 100);
	img.adress = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_len, &img.endian);
	draw_map(img, argv[1]);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 50, 50);
	mlx_hook(vars.win, 2, 1L<<0, &close_win, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
