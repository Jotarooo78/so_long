/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:42:56 by armosnie          #+#    #+#             */
/*   Updated: 2025/04/29 15:34:05 by marvin           ###   ########.fr       */
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
		ft_printf("size : %d | %s\n", i, map[i]);
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
	int win_height;
	int win_width;

	win_height = data->map_y * 16;
	win_width = data->map_x * 16;
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (ft_putstr_fd("Failed to init mlx", 2), false);
	data->win = mlx_new_window(data->mlx, win_width , win_height, "so_long");
	if (data->win == NULL)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		return (ft_putstr_fd("Failed to init window", 2), false);
	}
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
		if (data == NULL)
			return (ft_putstr_fd("Failed to malloc data", 2), 1);
		if (init_map(data, argv[1]) == false)
			return (exit_game(data, 1));
		if (init_game_data(data) == false)
			return (exit_game(data, 1));
		if (manage_init_texture(data) == false)
			return (exit_game(data, 1));
		init_move_input(data);
		mlx_loop(data->mlx);
		exit_game(data, 0);
		return (0);
	}
	return (ft_putstr_fd("invalid number of argument\n", 2), 1);
}
