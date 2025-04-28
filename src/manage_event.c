/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:36:41 by armosnie          #+#    #+#             */
/*   Updated: 2025/04/28 17:43:09 by marvin           ###   ########.fr       */
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
      data->player_x = new_x;
      data->player_y = new_y;
      data->move++;
      printf("Mouvements : %d\n", data->move);       
      display_map(data);
   }
   return (0);
}

void    init_move_input(t_game *data)
{
   mlx_key_hook(data->win, &handle_key, data);
}