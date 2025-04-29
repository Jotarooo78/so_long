/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:08:20 by armosnie          #+#    #+#             */
/*   Updated: 2025/04/29 15:54:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

bool	check_after_fill(t_game *data, char **dup_map)
{
	int	y;
	int	x;
	int	collect;

	collect = 0;
	y = 0;
	while (y < data->map_y)
	{
		x = 0;
		while (x < data->map_x)
		{
			if (dup_map[y][x] == 'C')
				collect++;
			x++;
		}
		y++;
	}
	if (collect != 0 || data->exit_exist != 1)
		return (false);
	return (true);
}

void	fill(t_game *data, char **dup_map, int y, int x)
{
	if (y < 0 || y >= data->map_y || x < 0 || x >= data->map_x
		|| dup_map[y][x] == 'F' || dup_map[y][x] == '1')
		return ;
	else if (dup_map[y][x] == 'E')
	{
		data->exit_exist = 1;
		return ;
	}
	dup_map[y][x] = 'F';
	fill(data, dup_map, y, x - 1);
	fill(data, dup_map, y, x + 1);
	fill(data, dup_map, y - 1, x);
	fill(data, dup_map, y + 1, x);
}

void	flood_fill(char **dup_map, t_game *data)
{
	fill(data, dup_map, data->player_y, data->player_x);
}

bool	check_path(t_game *data, int size)
{
	char **dup_map;

	dup_map = duplicate_map(data->map, size);
	if (dup_map == NULL)
		return (false);
	flood_fill(dup_map, data);
	if (check_after_fill(data, dup_map) == false)
	{
		ft_putstr_fd("Error\nunwinnable map\n", 2);
		free_array(dup_map);
		return (false);
	}
	free_array(dup_map);
	return (true);
}
