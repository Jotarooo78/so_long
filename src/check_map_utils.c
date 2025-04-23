/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:17:08 by armosnie          #+#    #+#             */
/*   Updated: 2025/04/23 16:27:49 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_player_position(t_game *mlxs, int x, int y)
{
	mlxs->player_x = x;
	mlxs->player_y = y;
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