/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 03:46:51 by gborne            #+#    #+#             */
/*   Updated: 2022/01/22 18:02:54 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_root	root;
	t_map	map;

	if(!init_map(argc, argv[1], &map))
		return (ft_printf("%s\n", map.error));
	init_root(&root, &map);
	init_screen(&root, &map);
	root.map = &map;
	mlx_hook(root.win, X_EVENT_KEY_PRESS, 1L<<0, &manage_key, &root);
	mlx_hook(root.win, X_EVENT_KEY_EXIT, 1L<<17, &close_win, &root);
	mlx_loop(root.mlx);
	free(map.map);
	return (0);
}
