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

typedef struct s_game
{
	int	collect;
	int	exit;
	int 	player;
	int		player_x;
	int		player_y;
	char	**map;
	void	*mlx;
	void	*win;
}			t_game;

void    print_map(t_game *mlxs);
bool  check_map(t_game *mlxs);
void    print_map(t_game *mlxs);
void    get_player_position(t_game *mlxs, int y, int x);
bool	init_map(t_game *mlxs, char *filename);
void		free_array(char **array);
void	free_struct(t_game *mlxs);
int	ft_error(char *str);

#endif