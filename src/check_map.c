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
	int x;
	int y;
	int len;

	x = 0;
	while (x < size)
	{
		len = ft_strlen(map[x]) - 1;
		if (x == 0 || x == (size))
		{
			y = 0;
			while (map[x][y])
			{
				if (map[x][y] != '1')
					return (ft_putstr_fd("invalid first or last wall\n", 2),
						false);
				y++;
			}
		}
		else if ((map[x][0] != '1') || (map[x][len] != '1'))
			return (ft_putstr_fd("invalid middle wall\n", 2), false);
		x++;
	}
	return (true);
}

bool	check_parameters(t_game *data, char **map, int size)
{
	int x;
	int y;
	int len;

	x = 1;
	while (x + 1 < size)
	{
		y = 1;
		len = ft_strlen(map[x]);
		while (y < len - 1)
		{
			if (map[x][y] == 'P')
				get_player_position(data, y, x);
			if (map[x][y] == 'C')
				data->collect++;
			if (map[x][y] == 'E')
				data->exit++;
			y++;
		}
		x++;
	}
	if (data->player != 1 || data->collect < 1 || data->exit != 1)
		return (ft_putstr_fd("wrong parameters setup\n", 2), false);
	return (true);
}

bool	check_rectangular_map(char **map, int size)
{
	int x;
	int len_x;
	int actual_len_x;

	if (size < 3)
		return (ft_putstr_fd("map is too small\n", 2), false);
	x = 0;
	len_x = ft_strlen(map[x]);
	while (x < size)
	{
		actual_len_x = ft_strlen(map[x]);
		if (x + 1 < size && actual_len_x == len_x - 1)
			return (true);
		if (actual_len_x != len_x)
			return (ft_putstr_fd("map isn't a rectangular\n", 2), false);
		x++;
	}
	return (true);
}

bool	check_map(t_game *data)
{
	data->collect = 0;
	data->exit = 0;
	data->player = 0;
	int size;

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
