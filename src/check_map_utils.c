/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:17:08 by armosnie          #+#    #+#             */
/*   Updated: 2025/04/22 17:13:50 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_player_position(t_game *mlxs, int x, int y)
{
	mlxs->player_x = x;
	mlxs->player_y = y;
	mlxs->player++;
}

int	get_len(char **map)
{
	int len;
	int i;

	len = 0;
	i = -1;
	while (map[++i])
		len++;
	return (len);
}