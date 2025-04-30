/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:43:25 by armosnie          #+#    #+#             */
/*   Updated: 2025/04/30 14:55:41 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

void	clean_data_up(t_game *data)
{
	if (data)
	{
		if (data->map)
			free_array(data->map);
		if (data->pics.wall_img.img)
			mlx_destroy_image(data->mlx, data->pics.wall_img.img);
		if (data->pics.exit_img.img)
			mlx_destroy_image(data->mlx, data->pics.exit_img.img);
		if (data->pics.collect_img.img)
			mlx_destroy_image(data->mlx, data->pics.collect_img.img);
		if (data->pics.player_img.img)
			mlx_destroy_image(data->mlx, data->pics.player_img.img);
		if (data->pics.backg_img.img)
			mlx_destroy_image(data->mlx, data->pics.backg_img.img);
		if (data->win)
			mlx_destroy_window(data->mlx, data->win);
		if (data->mlx)
		{
			mlx_destroy_display(data->mlx);
			free(data->mlx);
		}
		free(data);
	}
}

int	exit_game(t_game *data, int err)
{
	if (data)
		clean_data_up(data);
	if (err == 1)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}
