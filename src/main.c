/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:42:56 by armosnie          #+#    #+#             */
/*   Updated: 2025/04/24 16:38:12 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (!map[i])
		{
			printf("Invalid map line at index %d\n", i);
			break ;
		}
		printf("size : %d | %s\n", i, map[i]);
		i++;
	}
}

bool	check_extention(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 4)
		return (false);
	if (ft_strncmp(file + (len - 4), ".ber", 4) == 0)
		return (true);
	return (false);
}

bool	init_game_data(t_game *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
	{
		ft_putstr_fd("Failed to init mlx", 2);
		return (false);
	}
	data->win = mlx_new_window(data->mlx, WDW_WIDTH, WDW_HEIGHT, "so_long");
	if (data->win == NULL)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		ft_putstr_fd("Failed to init mlx (window)", 2);
		return (false);
	}
	mlx_loop(data->mlx);
	if (init_pics(data) == false)
		return (false);
	return (true);
}

int	main(int argc, char **argv)
{
	t_game	*data;

	if (argc == 2)
	{
		if ((check_extention(argv[1]) == false) || (argv[1] == NULL))
			return (ft_putstr_fd("invalid map format\n", 2), 1);
		data = malloc(sizeof(t_game));
		if (data == NULL || data == NULL)
			return (ft_putstr_fd("Failed to malloc data", 2), 1);
		if (init_map(data, argv[1]) == false)
			return (free(data), 1);
		if (init_game_data(data) == false)
            return (free(data), 1);
		free(data);
		return (0);
	}
	ft_error("invalid number of argument\n");
}
