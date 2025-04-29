/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:42:52 by marvin            #+#    #+#             */
/*   Updated: 2025/04/29 15:32:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void  refresh_player_pos(t_game *data, int new_y, int new_x)
{
   data->move++;
   ft_printf("Mouvements : %d\n", data->move);
   if (data->map[new_y][new_x] == 'C')
      data->collect--;
   else if (data->map[new_y][new_x] == 'E' && data->collect == 0)
   {
      ft_printf("you did it (b ᵔ▽ᵔ)b\n");
      exit_game(data, 0);
   }
   data->map[data->player_y][data->player_x] = '0';
   data->player_x = new_x;
   data->player_y = new_y;
   data->map[data->player_y][data->player_x] = 'P';
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
      return (exit_game(data, 0));
   if (data->map[new_y][new_x] != '1' && (data->player_y != new_y || data->player_x != new_x))
      refresh_player_pos(data, new_y, new_x);
   return (0);
}

void    init_move_input(t_game *data)
{
   mlx_hook(data->win, CROIX, 0, &exit_game, data);
   mlx_key_hook(data->win, &handle_key, data);
}