/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 03:46:39 by gborne            #+#    #+#             */
/*   Updated: 2022/01/24 05:54:01 by gborne           ###   ########.fr       */
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

typedef struct	s_player {
	int			count;
	int			x;
	int			y;
	int			coll;
	int			exit;
}				t_player;

typedef struct	s_map {
	int			x_max;
	int			y_max;
	int			coll;
	int			exit;
	int			player;
	char		*temp_map;
}				t_map;

typedef struct	s_root {
	void		*mlx;
	void		*win;
	char		*address;
	void		*img;
	int			bits_per_pixel;
	int			line_len;
	int			endian;
	void		*img_player;
	void		*img_ground;
	void		*img_wall;
	void		*img_coll;
	void		*img_exit;
	char		*error;
	char		**map;
	t_map		*s_map;
	t_player	*player;
}				t_root;

// manage_key.c
int			close_win(t_root *root);
int			detect_cell(t_root *root, char cell);
void		manage_move(t_root *root, int key);
int			manage_key(int key, t_root *root);
void		move_sprite(t_root *root, int y, int x);

// init_map.c
int			init_map(int argc, char *file, t_root *root);
void		construct_map(t_root *root);
void		check_line(t_root *root, char *line);
void		check_last(t_root *root);

// init_img.c
void		init_img(t_root *root);
void		init_sprite(t_root *root);
void		*get_img_sprite(t_root *root, char *path);

// init_screen.c
int			init_screen(t_root *root);
void		generate_img(t_root *root, int x, int y, char c);

// init_root.c
t_player	*init_s_player(t_player *player);
t_map		*init_s_map(t_map *map);
t_root		*init_root(t_root *root, t_map *map, t_player *s_player);
void		init_player(t_root *root, int i);

#endif
