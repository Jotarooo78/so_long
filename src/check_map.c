/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 19:01:23 by marvin            #+#    #+#             */
/*   Updated: 2025/04/17 19:01:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

bool  check_wall(char **map, int size)
{
   int y;
   int x;
   int len;

   y = 0;
   len = ft_strlen(map[y]) - 1;
   while (y < size)
   {
      if (y == 0 || y == (size - 1))
      {
         x = 0;
         while (map[y][x + 1])
         {
            if (map[y][x] != '1')
               ft_putstr_fd("invalid first or last wall\n", 2); 
            x++;
         }
      }
      else
         if ((map[y][0] != '1') || (map[y][len] != '1'))
            ft_putstr_fd("invalid middle wall\n", 2);
      y++;
   }
   return (true);
}

bool  check_map(char **map, int size)
{
   if (check_wall(map, size) == false)
      return (false);
   return (0);
}