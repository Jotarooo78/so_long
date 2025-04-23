/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:08:20 by armosnie          #+#    #+#             */
/*   Updated: 2025/04/23 17:04:33 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

bool	check_fill_map(char **map, int size)
{
	int x;
	int y;
	int len;

	y = 1;
	while (y + 1 < size)
	{
		x = 1;
		len = ft_strlen(map[x]);
		while (x < len - 1)
		{
            if (map[y][x] != 'F')
                return (ft_putstr_fd("unwinnable map\n", 2), false);
            x++;
		}
		y++;
	}
	return (true);
}

char	**duplicate_map(char **map, int size)
{
	char	**dup_map;
	int		i;

	dup_map = malloc(sizeof(char *) * (size + 1));
	if (dup_map == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		dup_map[i] = ft_strdup(map[i]);
		if (dup_map[i] == NULL)
			return (free_array(dup_map), NULL);
		i++;
	}
	dup_map[i] = NULL;
	return (dup_map);
}

void	fill(t_game *mlxs, char **dup_map, int y, int x, char to_fill)
{
	if (y < 0 || y >= mlxs->map_y || x < 0 || x >= mlxs->map_x || dup_map[y][x] != to_fill)
        return;
	dup_map[y][x] = 'F';
	fill(mlxs, dup_map, y - 1, x, to_fill);
	fill(mlxs, dup_map, y + 1, x, to_fill);
	fill(mlxs, dup_map, y, x - 1, to_fill);
	fill(mlxs, dup_map, y, x + 1, to_fill);
}

void	flood_fill(char **dup_map, t_game *mlxs)
{
	char to_fill;
	// (void)mlxs;
	// (void)dup_map;
	// (void)to_fill;
	
	to_fill = dup_map[mlxs->player_y][mlxs->player_x];
	// printf("dup_map :\n");
	// print_map(dup_map);
	// printf("\n");
	printf("map :\n");
	print_map(mlxs->map);
	printf("\n");
	// printf("player y position : %d\nplayer x position : %d\n", mlxs->player_y, mlxs->player_x);
	printf("map y : %d\nmap x : %d\n", mlxs->map_y, mlxs->map_x);

	fill(mlxs, dup_map, mlxs->player_y, mlxs->player_x,
			dup_map[mlxs->player_y][mlxs->player_x]); // segfault
}

bool	check_path(t_game *mlxs, int size)
{
	char **dup_map;

	dup_map = duplicate_map(mlxs->map, size);
	if (dup_map == NULL)
		return (false);
	flood_fill(dup_map, mlxs);
	if (check_fill_map(dup_map, size) == false)
	{
		print_map(dup_map);
	    ft_putstr_fd("unwinnable map\n", 2);
	    // free_array(dup_map);
	}
	else
		printf("yes");
	free_array(dup_map);
	return (true);
}