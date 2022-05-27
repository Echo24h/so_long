/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 03:46:51 by gborne            #+#    #+#             */
/*   Updated: 2022/05/27 14:25:08 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_root		root;
	t_map		map;
	t_player	s_player;

	init_root(&root, &map, &s_player);
	if (!init_map(argc, argv[1], &root) || !init_img(&root))
		close_win(&root);
	init_screen(&root);
	mlx_hook(root.win, X_EVENT_KEY_PRESS, 1L << 0, &manage_key, &root);
	mlx_hook(root.win, X_EVENT_KEY_EXIT, 1L << 17, &close_win, &root);
	mlx_loop(root.mlx);
	return (0);
}
