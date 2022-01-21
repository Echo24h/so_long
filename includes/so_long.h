/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 03:46:39 by gborne            #+#    #+#             */
/*   Updated: 2022/01/21 12:35:03 by gborne           ###   ########.fr       */
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

# define SPRITE_Y				64
# define SPRITE_X				64

typedef struct	s_map {
	size_t	x_max;
	size_t	y_max;
	size_t	coll;
	size_t	exit;
	size_t	player;
	char	*error;
	char	*map;
}				t_map;

typedef struct	s_img {
	void	*img;
	int		width;
	int		height;
}				t_img;

typedef struct	s_root {
	void	*mlx;
	void	*win;
	char	*address;
	void	*img;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
	void	*player;
	void	*ground;
	void	*wall;
	void	*coll;
	void	*exit;
}				t_root;

// utils.c
int				close_win(int key, t_root *vars);

// init_map.c
int				init_map(int argc, char *file, t_map *map);
void			check_line(char *line, t_map *map);
void			check_last(t_map *map);
void			init_s_map(t_map *map);

// init_root.c
void			init_root(t_root *root, t_map *map);
void			texture_init(t_root *root);
void			*texture_load(t_root *root, char *path);

//draw_map.c
void			draw_map(t_img object, t_map map);
void			draw_square(t_img object, int len, int heigh, int color);

//mlx_utils.c
void			my_mlx_pixel_put(t_root *data, int x, int y, int color);
unsigned int	my_mlx_get_pixel_color(int x, int y, void *sprite);

#endif
