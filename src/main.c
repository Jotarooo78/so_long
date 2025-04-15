/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:42:56 by armosnie          #+#    #+#             */
/*   Updated: 2025/04/15 16:38:04 by armosnie         ###   ########.fr       */
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

static void    init_mlx_wdw_data(t_fractal *fractal)
{
    fractal->mlx_connection = mlx_init();
    if (NULL == fractal->mlx_connection)
    {
        ft_putstr_fd("Failed to init mlx_connection", 2);
        exit(EXIT_FAILURE);
    }
    fractal->mlx_window = mlx_new_window(fractal->mlx_connection,
            WDW_WIDTH, WDW_HEIGHT,
            fractal->name);
    if (NULL == fractal->mlx_window)
    {
        mlx_destroy_display(fractal->mlx_connection);
        free(fractal->mlx_connection);
        ft_putstr_fd("Failed to init mlx (window)", 2);
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char **argv)
{
    void *mlx;
    void *win;

    if (argc == 2)
    {
        if (check_ext(argv[1]) == false)
            ft_error("invalid map format\n", 1);
        mlx = mlx_init();
        if (mlx == NULL)
        win = mlx_new_window(mlx, 800, 600, "so_long_test\n");
        
        mlx_loop(mlx);
        return (0);
    }
    ft_error("invalid number of argument\n", 1);
}