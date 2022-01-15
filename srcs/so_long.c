/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 16:06:29 by dalves-p          #+#    #+#             */
/*   Updated: 2022/01/15 05:25:41 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct	s_draw {
	void	*img;
	char	*adress;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
	int		x;
	int		y;
}				t_draw;

void	my_mlx_pixel_put(t_draw *data, int x, int y, int color)
{
	char	*dst;

	dst = data->adress + (y * data->line_len + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_square(t_draw object, int len, int heigh, int color)
{
	while (object.x < len)
	{
		my_mlx_pixel_put(&object, object.x, object.y, color);
		object.x++;
	}
	while (object.y < heigh)
	{
		my_mlx_pixel_put(&object, object.x, object.y, color);
		object.y++;
	}
	while (object.x > 0)
	{
		my_mlx_pixel_put(&object, object.x, object.y, color);
		object.x--;
	}
	while (object.y > 0)
	{
		my_mlx_pixel_put(&object, object.x, object.y, color);
		object.y--;
	}
}

void	draw_line(t_draw object, char *line)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (line[i] != '\n')
	{
		x += 50;
		i++;
	}
	//draw_square(object, 50, y, 0x054362F);
}

void	draw_map(t_draw object, char *argv)
{
	int		fd;
	char	*line;

	fd = open(argv, O_RDONLY);
	line = "";
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			free(line);
			close(fd);
			exit(1);
		}
		draw_line(object, line);
		ft_printf("%s", line);
	}
}

int	ft_puterror(int argc)
{
	if (argc < 2)
		ft_printf("Entrez une map.");
	else
		ft_printf("Veuillez choisir qu'une seule map.");
	return (0);
}

int	check_map(char *map)
{
	if (map == NULL)
		return (0);
	return (1);
}

int	close_win(int key, t_vars *vars)
{
	ft_printf("Key de la touche : %d", key);
	mlx_destroy_window(vars->mlx, vars->win);
	free(vars->mlx);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_draw	img;

	if (argc != 2 || !check_map(argv[1]))
		return (ft_puterror(argc));
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
