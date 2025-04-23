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

bool	check_parameters(t_game *mlxs, char **map, int size)
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
				get_player_position(mlxs, y, x);
			if (map[x][y] == 'C')
				mlxs->collect++;
			if (map[x][y] == 'E')
				mlxs->exit++;
			y++;
		}
		x++;
	}
	// printf("%d %d %d\n", mlxs->player, mlxs->collect, mlxs->exit);
	if (mlxs->player != 1 || mlxs->collect < 1 || mlxs->exit != 1)
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

bool	check_map(t_game *mlxs)
{
	mlxs->collect = 0;
	mlxs->exit = 0;
	mlxs->player = 0;
	int size;

	size = get_x_y_size(mlxs, mlxs->map);
	if (check_wall(mlxs->map, size) == false)
		return (false);
	if (check_parameters(mlxs, mlxs->map, size) == false)
		return (false);
	if (check_rectangular_map(mlxs->map, size) == false)
		return (false);
	if (check_path(mlxs, size) == false)
		return (false);
	return (true);
}
