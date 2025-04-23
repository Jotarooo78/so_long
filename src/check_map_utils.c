/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:17:08 by armosnie          #+#    #+#             */
/*   Updated: 2025/04/23 18:44:41 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_player_position(t_game *mlxs, int x, int y)
{
	mlxs->player_x = x;
	mlxs->player_y = y;
	mlxs->exit_exist = 0;
	mlxs->player++;
}

int	get_x_y_size(t_game *mlxs, char **map)
{
	int y;
	int x;

	x = 0;
	y = 0;
	while (map[y][x])
		x++;
	while (map[y])
		y++;
	mlxs->map_y = y;
	mlxs->map_x = x;
	return (y);
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
