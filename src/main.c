/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:42:56 by armosnie          #+#    #+#             */
/*   Updated: 2025/04/24 13:39:22 by armosnie         ###   ########.fr       */
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

bool	init_mlx_data(t_mlx *data2)
{
	data2->mlx = mlx_init();
	if (data2->mlx == NULL)
	{
		ft_putstr_fd("Failed to init mlx", 2);
		exit(EXIT_FAILURE);
		return (false);
	}
	data2->win = mlx_new_window(data2->mlx, WDW_WIDTH, WDW_HEIGHT, "so_long");
	if (data2->win == NULL)
	{
		mlx_destroy_display(data2->mlx);
		free(data2->mlx);
		ft_putstr_fd("Failed to init mlx (window)", 2);
		return (false);
	}
	return (true);
}

int	main(int argc, char **argv)
{
	t_game	*data;
	t_mlx	*data2;

	if (argc == 2)
	{
		if ((check_extention(argv[1]) == false) || (argv[1] == NULL))
			return (ft_putstr_fd("invalid map format\n", 2), 1);
		data = malloc(sizeof(t_game));
		data2 = malloc(sizeof(t_mlx));
		if (data == NULL || data2 == NULL)
			return (ft_putstr_fd("Failed to malloc data or data 2", 2), 1);
		if (init_map(data, argv[1]) == false)
			return (free(data), free(data2), 1);
		if (init_mlx_data(data2) == false)
            return (free(data), free(data2), 1);
		mlx_loop(data2->mlx);
		free_array(data->map);
		free(data);
		return (0);
	}
	ft_error("invalid number of argument\n");
}
