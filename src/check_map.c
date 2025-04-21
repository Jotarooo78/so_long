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

int	get_len(char **map)
{
	int		len;
   int i;

	len = 0;
   i = -1;
	while (map[++i])
      len++;
	return (len);
}

bool  check_wall(char **map, int size)
{
   int y;
   int x;
   int len;

   y = 0;
   while (y < size)
   {
      len = ft_strlen(map[y]) - 1;
      if (y == 0 || y == (size))
      {
         x = 0;
         while (map[y][x])
         {
            if (map[y][x] != '1')
               return (ft_putstr_fd("invalid first or last wall\n", 2), false); 
            x++;
         }
      }
      else
         if ((map[y][0] != '1') || (map[y][len] != '1'))
            return (ft_putstr_fd("invalid middle wall\n", 2), false);
      y++;
   }
   return (true);
}

bool  check_parameters(t_game *mlxs, char **map, int size)
{
   int y;
   int x;
   int len;

   y = 1;
   while (y + 1 < size)
   {
      x = 1;
      len = ft_strlen(map[y]);
      while (x < len - 1)
      {
         if (map[y][x] == 'P')
            mlxs->player++;
         if (map[y][x] == 'C')
            mlxs->collect++;
         if (map[y][x] == 'E')
            mlxs->exit++;
         x++;
      }
      y++;
   }
   if (mlxs->player != 1 || mlxs->collect < 1 || mlxs->exit != 1)
      return (ft_putstr_fd("wrong parameters setup\n", 2), false);
   return (true);
}

bool  chec_rectangular_map(char **map, int size)
{
   int y;
   int len_y;
   int actual_len_y;

   y = 0;
   len_y = ft_strlen(map[y]);
   while (y < size)
   {
      actual_len_y = ft_strlen(map[y]);
      if (y + 1 < size && actual_len_y == len_y - 1)
         return (true);
      if (actual_len_y != len_y)
         return (ft_putstr_fd("wrong map format\n", 2), false);
      y++;
   }
   return (true);
}

bool  check_map(t_game *mlxs)
{
   mlxs->collect = 0;
   mlxs->exit = 0;
   mlxs->player = 0;
   int size;

   size = get_len(mlxs->map);
   printf("\nlen : %d\n", size);
   if (check_wall(mlxs->map, size) == false)
      return (false);
   if (check_parameters(mlxs, mlxs->map, size) == false)
      return (false);
   if (chec_rectangular_map(mlxs->map, size) == false)
      return (false);
   else
      free_array(mlxs->map);
   return (true);
}
