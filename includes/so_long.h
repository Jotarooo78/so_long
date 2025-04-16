#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../libx/mlx.h"
# include "../libx/mlx_int.h"
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>

# define EXIT_FAILURE 1
# define WDW_WIDTH 800
# define WDW_HEIGHT 600

typedef struct s_game
{
    char    **map;
    int     width;
    int     height;
    int     count_p;
    int     count_e;
    int     count_c;
} t_game;

typedef struct s_mlx
{
    void    *window;
    void    *mlx;
    char    *file;

} t_mlx;
int	ft_error(char *str, int code_error);


#endif