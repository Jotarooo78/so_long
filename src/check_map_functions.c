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

bool  check_first_last_wall(char **map, int lign)
{
   size_t i;

   i = 0;
   while (map[lign][i] == 1 && i < ft_strlen(map[lign]))
   {
      if (map[lign][i] != 1)
         return (false); 
      i++;
   }
   return (true);
}

bool  check_middle_wall(char **map, int lign)
{
   int check;
   size_t i;

   i = 0;
   check = 0;
   while (map[lign][i])
   {
      if ((map[lign][0] == 1))
         check++;
      else if ((ft_strlen(map[lign]) - 1) == 1)
         check++;
      i++;
   }
   printf("%d\n", check);
   if (check != 2)
      return (ft_putstr_fd("invalid middle wall lign\n", 2), false);
   return (true);
}

bool  check_wall(char **map, int size)
{
   int lign;

   lign = 0;
   while (lign < size)
   {
      if (lign == 0 || lign == (size - 1))
      {
         if (check_first_last_wall(map, lign) == false)
            return (ft_putstr_fd("invalid first or last wall lign\n", 2), false);
      }
      else
      {
         if (check_middle_wall(map, lign) == false)
            return (ft_putstr_fd("invalid middle wall lign\n", 2), false);
      }
      lign++;
   }
   return (true);
}

bool  check_map(char **map, int size)
{
   if (check_wall(map, size) == false)
      return (ft_putstr_fd("invalid fd 1\n", 2), false);
   return (0);
}