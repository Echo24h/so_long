/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 03:46:39 by gborne            #+#    #+#             */
/*   Updated: 2022/01/19 06:40:05 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# if defined(__APPLE__) && defined(__MACH__)
#  include "../mlx/mlx.h"
# else
#  include "../mlx_linux/mlx.h"
# endif

# include "../libft/libft.h"

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_EXIT		17

# if defined(__APPLE__) && defined(__MACH__)
#  define LEFT_KEY				123
#  define RIGHT_KEY				124
#  define UP_KEY				126
#  define DOWN_KEY				125
#  define A_KEY					0
#  define S_KEY					1
#  define D_KEY					2
#  define W_KEY					13
#  define ESC 					53

# else
#  define LEFT_KEY				65361
#  define RIGHT_KEY				65363
#  define UP_KEY				65362
#  define DOWN_KEY				65364
#  define A_KEY					97
#  define W_KEY					119
#  define S_KEY					115
#  define D_KEY					100
#  define ESC					65307
# endif

# define SPRITE_H				64
# define SPRITE_W				64

typedef struct	s_win {
	void	*mlx;
	void	*win;
}				t_win;

typedef struct	s_map {
	size_t	height;
	size_t	wight;
	char	*error;
	char	*map;
}				t_map;

typedef struct	s_img {
	void	*img;
	char	*adress;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
	int		x;
	int		y;
}				t_img;

// init_map.c

void	init_s_map(t_map *map);
char	*check_map(int argc, char *file);
int		init_map(int argc, char *file, t_map *map);

// utils.c

int		ft_puterror(char *error);
int		close_win(int key, t_win *vars);

//draw_map.c

void	draw_map(t_img object, char *map);
void	draw_square(t_img object, int len, int heigh, int color);

//draw_map_utils.c

void	my_mlx_pixel_put(t_img *data, int x, int y, int color);

#endif
