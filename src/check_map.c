/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/04/17 19:01:23 by marvin            #+#    #+#             */
/*   Updated: 2025/04/17 19:01:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

bool	check_wall(char **map, int size)
{
	int		x;
	int		y;
	int		len;

	y = 0;
	while (y < size)
	{
		len = ft_strlen(map[y]) - 1;
		if (y == 0 || y == (size))
		{
			x = 0;
			while (map[y][x])
			{
				if (map[y][x] != '1')
					return (ft_putstr_fd("Error\ninvalid first or last wall\n",
							2), false);
				x++;
			}
		}
		else if ((map[y][0] != '1') || (map[y][len] != '1'))
			return (ft_putstr_fd("Error\ninvalid middle wall\n", 2), false);
		y++;
	}
	return (true);
}

bool	check_parameters(t_game *data, char **map, int size)
{
	int		x;
	int		y;
	int		len;

	y = 1;
	len = ft_strlen(map[y]);
	while (y + 1 < size)
	{
		x = 1;
		while (x < len - 1)
		{
			if (map[y][x] == 'P')
				get_player_position(data, y, x);
			if (map[y][x] == 'C')
				data->collect++;
			if (map[y][x] == 'E')
				data->exit++;
			x++;
		}
		y++;
	}
	if (data->player != 1 || data->collect < 1 || data->exit != 1)
		return (ft_putstr_fd("Error\nwrong parameters setup\n", 2), false);
	return (true);
}

bool	check_rectangular_map(char **map, int size)
{
	int		y;
	int		len_y;
	int		actual_len_y;

	if (size < 3)
		return (ft_putstr_fd("Error\nmap is too small\n", 2), false);
	y = 0;
	len_y = ft_strlen(map[y]);
	while (y < size)
	{
		actual_len_y = ft_strlen(map[y]);
		if (y + 1 < size && actual_len_y == len_y - 1)
			return (true);
		if (actual_len_y != len_y)
			return (ft_putstr_fd("Error\nmap isn't a rectangular\n", 2),
				false);
		y++;
	}
	return (true);
}

bool	check_map(t_game *data)
{
	int		size;

	data->collect = 0;
	data->exit = 0;
	data->player = 0;
	size = get_x_y_size(data, data->map);
	if (check_wall(data->map, size) == false)
		return (false);
	if (check_parameters(data, data->map, size) == false)
		return (false);
	if (check_rectangular_map(data->map, size) == false)
		return (false);
	if (check_path(data, size) == false)
		return (false);
	return (true);
}
