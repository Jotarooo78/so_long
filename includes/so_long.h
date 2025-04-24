#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../libx/mlx.h"
# include "../libx/mlx_int.h"
# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>

# define EXIT_FAILURE 1
# define WDW_WIDTH 800
# define WDW_HEIGHT 600
# define BUFFERSIZE 4096

typedef	struct s_sprit
{
	void *img;
	int		height;
	int		widht;
}	t_sprit;

typedef struct s_pixel
{
	t_sprit	wall_img;
	t_sprit	backg_img;
	t_sprit	exit_img;
	t_sprit	collect_img;
	t_sprit	player_img;
}	t_pixel;

typedef struct s_game
{
	int		collect;
	int		exit;
	int		exit_exist;
	int		player;
	int		player_x;
	int		player_y;
	int		map_x;
	int		map_y;
	int		img_width;
	int		img_height;
	char	**map;
	void	*mlx;
	void	*win;
	t_pixel	pics;
}			t_game;

bool		init_pics(t_game *data);

char		**duplicate_map(char **map, int size);
bool		check_path(t_game *mlxs, int size);
int			get_x_y_size(t_game *mlxs, char **map);
void		get_player_position(t_game *mlxs, int y, int x);
void		print_map(char **map);
bool		check_map(t_game *mlxs);
void		get_player_position(t_game *mlxs, int y, int x);
bool		init_map(t_game *mlxs, char *filename);

void		free_array(char **array);
int			ft_error(char *str);

#endif