/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:42:56 by armosnie          #+#    #+#             */
/*   Updated: 2025/04/16 17:50:30 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


bool    check_ext(char *file)
{
    int len;

    len = ft_strlen(file);
    if (len < 4)
        return (false);
    if (ft_strncmp(file + (len - 4), ".ber", 4) == 0)
        return (true);
    return (false);
}

bool    init_mlx_data(t_game *mlxs)
{
    char	**map = NULL;

    mlxs->mlx = mlx_init();
    if (mlxs->mlx == NULL)
    {
        ft_putstr_fd("Failed to init mlx", 2);
        exit(EXIT_FAILURE);
        return (false);
    }
    mlxs->mlx_win = mlx_new_window(mlxs->mlx,
            WDW_WIDTH, WDW_HEIGHT, "so_long");
    if (mlxs->mlx_win == NULL)
    {
        mlx_destroy_display(mlxs->mlx);
        free(mlxs->mlx);
        ft_putstr_fd("Failed to init mlx (window)", 2);
        return (false);
    }
    return (true);
}

int main(int argc, char **argv)
{
    t_game *mlxs;

    if (argc == 2)
    {
        if ((check_ext(argv[1]) == false) || (argv[1] == NULL) || (argv[1][0] = NULL))
            ft_error("invalid map format\n", 1);
        if (init_mlx_data(mlxs) == 0)
            return (1);
        init_map(mlxs, argv[1]);
        // mlx_loop(mlxs->mlx);
        return (0);
    }
    ft_error("invalid number of argument\n", 1);
}