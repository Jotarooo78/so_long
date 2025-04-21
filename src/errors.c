/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:43:25 by armosnie          #+#    #+#             */
/*   Updated: 2025/04/21 15:30:55 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_struct(t_game *mlxs)
{
	if (mlxs->map)
		free(mlxs->map);
	if (mlxs->win)
	{
		if (mlxs->win)
			mlx_destroy_window(mlxs->win, mlxs->win);
		mlx_destroy_display(mlxs->mlx);
		free(mlxs->win);
	}
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	ft_error(char *str)
{
	ft_printf(str);
	exit(EXIT_FAILURE);
}
