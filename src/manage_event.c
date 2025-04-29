/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:42:52 by marvin            #+#    #+#             */
/*   Updated: 2025/04/29 12:54:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void  refresh_player_pos(t_game *data, int new_y, int new_x)
{
   data->map[data->player_y][data->player_x] = '0';
   data->player_x = new_x;
   data->player_y = new_y;
   data->map[data->player_y][data->player_x] = 'P';
   data->move++;
   printf("Mouvements : %d\n", data->move);
   display_map(data);
}

int handle_key(int keycode, t_game *data)
{
   int new_x;
   int new_y;

   new_x = data->player_x;
   new_y = data->player_y;
    
   if (keycode == W && data->map[new_y][new_x] != '1')
      new_y--;
   else if (keycode == S && data->map[new_y][new_x] != '1')
      new_y++;
   else if (keycode == A && data->map[new_y][new_x] != '1')
      new_x--;    
   else if (keycode == D && data->map[new_y][new_x] != '1')
      new_x++;    
   else if (keycode == ESC)
      return (exit_game(data));
   if (data->map[new_y][new_x] != '1' && data->player_y != new_y && data->player_x != new_x)
      refresh_player_pos(data, new_y, new_x);
   return (0);
}

void    init_move_input(t_game *data)
{
   mlx_key_hook(data->win, &handle_key, data);
}
// print_map(data->map);
// printf("Old position: (%d, %d)\n", data->player_y, data->player_x);
// printf("New position: (%d, %d)\n", new_y, new_x);
// printf("Map before update:\n");
// printf("ending fill at: (%d, %d)\n", data->player_y, data->player_x);
// printf("Starting fill at: (%d, %d)\n", data->player_y, data->player_x);