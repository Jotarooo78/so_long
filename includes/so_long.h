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
	char	**map;
	void	*mlx;
	void	*mlx_win;
}			t_game;

void    print_map(t_game *mlxs);
bool  check_map(t_game *mlxs);
void    print_map(t_game *mlxs);
bool	init_map(t_game *mlxs, char *filename);
void		free_array(char **array);
int	ft_error(char *str);

#endif