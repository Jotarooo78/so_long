/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:17:08 by armosnie          #+#    #+#             */
/*   Updated: 2025/04/28 17:32:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_player_position(t_game *data, int x, int y)
{
	data->player_x = x;
	data->player_y = y;
	data->exit_exist = 0;
	data->player++;
}

int	get_x_y_size(t_game *data, char **map)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	while (map[y][x])
		x++;
	while (map[y])
		y++;
	data->map_y = y;
	data->map_x = x;
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
