/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:42:52 by marvin            #+#    #+#             */
/*   Updated: 2025/04/28 19:07:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int handle_key(int keycode, t_game *data)
{
   int new_x;
   int new_y;

   new_x = data->player_x;
   new_y = data->player_y;
    
   if (keycode == W)
      new_y--;
   else if (keycode == S)
      new_y++;
   else if (keycode == A)
      new_x--;    
   else if (keycode == D)
      new_x++;    
   else if (keycode == ESC)
      return (exit_game(data));
   if (data->map[new_y][new_x] != '1')
   {
      printf("Old position: (%d, %d)\n", data->player_y, data->player_x);
      printf("New position: (%d, %d)\n", new_y, new_x);
      printf("Map before update:\n");
      data->map[data->player_y][data->player_x] = '0';
      printf("Starting fill at: (%d, %d)\n", data->player_y, data->player_x);
      data->player_x = new_x;
      data->player_y = new_y;
      printf("ending fill at: (%d, %d)\n", data->player_y, data->player_x);
      data->map[data->player_y][data->player_x] = 'P';
      data->move++;
      printf("Mouvements : %d\n", data->move);
      print_map(data->map);      
      display_map(data);
      print_map(data->map);
   }
   return (0);
}

void    init_move_input(t_game *data)
{
   mlx_key_hook(data->win, &handle_key, data);
}