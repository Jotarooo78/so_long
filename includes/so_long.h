/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:00:41 by armosnie          #+#    #+#             */
/*   Updated: 2025/04/30 15:00:43 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../libx/mlx.h"
# include "../libx/mlx_int.h"
# include <stdbool.h>
# include <unistd.h>

# define EXIT_FAILURE 1
# define WDW_WIDTH 800
# define WDW_HEIGHT 600
# define BUFFERSIZE 4096

# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307
# define CROIX 17

typedef struct s_sprite
{
	void		*img;
	int			height;
	int			widht;
}				t_sprite;

typedef struct s_pixel
{
	t_sprite	wall_img;
	t_sprite	backg_img;
	t_sprite	exit_img;
	t_sprite	collect_img;
	t_sprite	player_img;
}				t_pixel;

typedef struct s_game
{
	int			collect;
	int			exit;
	int			exit_exist;
	int			player;
	int			player_x;
	int			player_y;
	int			map_x;
	int			map_y;
	int			img_width;
	int			img_height;
	int			move;
	char		**map;
	void		*mlx;
	void		*win;
	t_pixel		pics;
}				t_game;

bool			manage_init_texture(t_game *data);
void			init_picture(t_game *data);
void			init_move_input(t_game *data);

void			display_map(t_game *data);
char			**duplicate_map(char **map, int size);
bool			check_path(t_game *mlxs, int size);
int				get_x_y_size(t_game *mlxs, char **map);
void			get_player_position(t_game *mlxs, int y, int x);
void			print_map(char **map);
bool			check_map(t_game *mlxs);
void			get_player_position(t_game *mlxs, int y, int x);
bool			init_map(t_game *mlxs, char *filename);

void			free_array(char **array);
int				exit_game(t_game *data, int err);

#endif