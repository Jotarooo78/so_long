/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:42:56 by armosnie          #+#    #+#             */
/*   Updated: 2025/04/16 11:53:12 by marvin           ###   ########.fr       */
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
    
}

bool    init_mlx_wdw_data(t_win win)
{
    win->mlx = mlx_init();
    if (win->mlx == NULL)
    {
        ft_putstr_fd("Failed to init mlx_connection", 2);
        exit(EXIT_FAILURE);
    }
    win->window = mlx_new_window(win->window,
            WDW_WIDTH, WDW_HEIGHT, "so_long");
    if (win->window == NULL)
    {
        mlx_destroy_display(win->mlx);
        free(win->mlx);
        ft_putstr_fd("Failed to init mlx window", 2);
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char **argv)
{
    t_win win;
    t_game game;
    
    if (argc == 2)
        ft_error("invalid number of argument\n", 1);
    if (check_ext(argv[1]) == false)
        ft_error("invalid map format\n", 1);
    if (init_mlx_wdw_data(&win) == false)
        return (NULL);
    mlx_loop(mlx);
    return (0);
}