/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:08:20 by armosnie          #+#    #+#             */
/*   Updated: 2025/04/22 17:56:13 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// bool	check_fill_map(char **map, int size)
// {
// 	int x;
// 	int y;
// 	int len;

// 	x = 1;
// 	while (x + 1 < size)
// 	{
// 		y = 1;
// 		len = ft_strlen(map[x]);
// 		while (y < len - 1)
// 		{
//             if (y != 'F')
//                 return (ft_putstr_fd("unwinnable map\n", 2), false);
//             y++;
// 		}
// 		x++;
// 	}
// 	return (true);
// }

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

void	fill(char **map, t_point size, t_point cur, char to_fill)
{
    printf("la\n");
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| map[cur.y][cur.x] != to_fill)
		return ;
	map[cur.y][cur.x] = 'F';
	fill(map, size, (t_point){cur.x - 1, cur.y}, to_fill);
	fill(map, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill(map, size, (t_point){cur.x, cur.y - 1}, to_fill);
	fill(map, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

void	flood_fill(char **map, t_game *mlxs)
{
	t_point	size;
	t_point	begin;

	print_map(map);
	size.x = mlxs->map_x;
	size.y = mlxs->map_y;
	// printf("size x : %d, ", size.x);
    // printf("size y : %d, ", size.y);
	begin.x = mlxs->player_x;
	begin.y = mlxs->player_y;
	// printf("player x : %d, ", begin.x);
	// printf("player y : %d\n", begin.y);
    if (begin.x < 0 || begin.x >= size.x || begin.y < 0 || begin.y >= size.y)
    {
        ft_putstr_fd("Invalid player position\n", 2);
        return;
    }
    printf("beg : %d\n", begin.x);
    printf("player y : %d\n", begin.y);
    // printf("%c\n", map[begin.y][begin.x]);
	// fill(map, size, begin, map[begin.y][begin.x]); // segfault
}

bool	check_path(t_game *mlxs, int size)
{
	char **dup_map;

	// (void)mlxs;
	// (void)size;
	// (void)dup_map;
	dup_map = duplicate_map(mlxs->map, size);
	if (dup_map == NULL)
		return (false);
	flood_fill(dup_map, mlxs);
	// if (check_fill_map(dup_map, size) == false)
	// {
	//     ft_putstr_fd("unwinnable map\n", 2);
	//     free_array(dup_map);
	//     return (false);
	// }
	free_array(dup_map);
	return (true);
}