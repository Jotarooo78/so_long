/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:08:20 by armosnie          #+#    #+#             */
/*   Updated: 2025/04/21 16:28:31 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void    get_player_position(t_game *mlxs, int y, int x)
{
    mlxs->player_x = x;
    mlxs->player_y = y;
    mlxs->player++;
}

void	fill(char **tab, t_game size, t_game cur, char visited)
{
	if (cur.player_y < 0 || cur.player_y >= size.player_y || cur.player_x < 0 || cur.player_x >= size.player_x
		|| tab[cur.player_y][cur.player_x] != visited)
		return;

	tab[cur.player_y][cur.player_x] = 'V';
	fill(tab, size, (t_game){cur.player_x - 1, cur.player_y}, visited);
	fill(tab, size, (t_game){cur.player_x + 1, cur.player_y}, visited);
	fill(tab, size, (t_game){cur.player_x, cur.player_y - 1}, visited);
	fill(tab, size, (t_game){cur.player_x, cur.player_y + 1}, visited);
}

void	flood_fill(char **tab, t_game size, t_game mlxs)
{
	fill(tab, size, mlxs, tab[mlxs.player_y][mlxs.player_x]);
}

void    check_path(t_game *mlxs, int size)
{
    char **dup_map;
    
    dup_map = malloc(sizeof(char *) * (size));
    if (dup_map == NULL)
        return (NULL);
    if (flood_fill() == )
}