/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:08:20 by armosnie          #+#    #+#             */
/*   Updated: 2025/04/23 19:06:05 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


bool	check_after_fill(t_game *mlxs, char **dup_map)
{
	int y;
	int x;
	int collect;

	collect = 0;
	y = 0;
	while (y < mlxs->map_y)
	{
		x = 0;
		while (x < mlxs->map_x)
		{
			if (dup_map[y][x] == 'C')
				collect++;
			x++;
		}
		y++;
	}
	if (collect != 0 || mlxs->exit_exist == 1)
	{
		printf("collect : %d\n", collect);
		return (false);
	}
	return (true);
}

void	fill(t_game *mlxs, char **dup_map, int y, int x)
{
	if (y < 0 || y >= mlxs->map_y || x < 0 || x >= mlxs->map_x || dup_map[y][x] == 'F' || dup_map[y][x] == '1')
        return;
	else if (dup_map[y][x] == 'E')
	{
		mlxs->exit_exist = '1';
		return ;
	}
	dup_map[y][x] = 'F';
	fill(mlxs, dup_map, y, x - 1);
	fill(mlxs, dup_map, y, x + 1);
	fill(mlxs, dup_map, y - 1, x);
	fill(mlxs, dup_map, y + 1, x);
}

void	flood_fill(char **dup_map, t_game *mlxs)
{
	char to_fill;
	
	to_fill = dup_map[mlxs->player_y][mlxs->player_x];
	// printf("dup_map :\n");
	// print_map(dup_map);
	// printf("\n");
	printf("map :\n");
	print_map(mlxs->map);
	printf("\n");
	// printf("player y position : %d\nplayer x position : %d\n", mlxs->player_y, mlxs->player_x);
	// printf("map y : %d\nmap x : %d\n", mlxs->map_y, mlxs->map_x);

	fill(mlxs, dup_map, mlxs->player_y, mlxs->player_x);
}

bool	check_path(t_game *mlxs, int size)
{
	char **dup_map;

	dup_map = duplicate_map(mlxs->map, size);
	if (dup_map == NULL)
		return (false);
	flood_fill(dup_map, mlxs);
	if (check_after_fill(mlxs, dup_map) == false)
	{
		print_map(dup_map);
	    ft_putstr_fd("unwinnable map\n", 2);
	}
	print_map(dup_map);
	free_array(dup_map);
	return (true);
}