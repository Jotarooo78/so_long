/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:42:56 by armosnie          #+#    #+#             */
/*   Updated: 2025/04/22 17:54:43 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void    print_map(char **map)
{
    int i = 0;
    
    while (map[i])
    {
        if (!map[i])
		{
			printf("Invalid map line at index %d\n", i);
			break;
		}
        printf("%s\n", map[i]);
        i++;
    }
}

bool    check_extention(char *file)
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
    mlxs->mlx = mlx_init();
    if (mlxs->mlx == NULL)
    {
        ft_putstr_fd("Failed to init mlx", 2);
        exit(EXIT_FAILURE);
        return (false);
    }
    mlxs->win = mlx_new_window(mlxs->mlx,
            WDW_WIDTH, WDW_HEIGHT, "so_long");
    if (mlxs->win == NULL)
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
        if ((check_extention(argv[1]) == false) || (argv[1] == NULL))
            return (ft_putstr_fd("invalid map format\n", 2), 1);
        mlxs = malloc(sizeof(t_game));
        if (!mlxs)
            return (ft_putstr_fd("Failed to malloc mlxs", 2), 1);
        init_map(mlxs, argv[1]);
        // if (init_mlx_data(mlxs) == false)
        //     ft_error("mlxs init failed\n", 1);
        // mlx_loop(mlxs->mlx);
        free_array(mlxs->map);
        free(mlxs);
        return (0);
    }
    ft_error("invalid number of argument\n");
}
