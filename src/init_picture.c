/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_picture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:18:21 by armosnie          #+#    #+#             */
/*   Updated: 2025/04/24 17:07:33 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	display_map(t_game *data, t_pixel *pics)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map_y)
	{
		x = 0;
		while (x < data->map_x)
		{
			if (data->map[y][x] == '1')
				mlx_put_image_to_window(data->mlx, data->win, pics->wall_img, x
					* 16, y * 16);
			if (data->map[y][x] == '0')
				mlx_put_image_to_window(data->mlx, data->win, pics->backg_img, x
					* 16, y * 16);
			if (data->map[y][x] == 'C')
				mlx_put_image_to_window(data->mlx, data->win, pics->collect_img,
					x * 16, y * 16);
			if (data->map[y][x] == 'E')
				mlx_put_image_to_window(data->mlx, data->win, pics->exit_img, x
					* 16, y * 16);
			if (data->map[y][x] == 'P')
				mlx_put_image_to_window(data->mlx, data->win, pics->player_img,
					x * 16, y * 16);
			x++;
		}
		y++;
	}
}

bool	init_picture(t_game *data, t_pixel *pics)
{
	data->img_height = 16;
	data->img_width = 16;
	pics->wall_img = mlx_xpm_file_to_image(data->mlx, "../asset/wall.xpm",
			&data->img_height, &data->img_width);
	if (pics->wall_img == NULL)
		return (ft_putstr_fd("invalid wall image\n", 2), false);
	pics->exit_img = mlx_xpm_file_to_image(data->mlx, "../asset/exit.xpm",
			&data->img_height, &data->img_width);
	if (pics->exit_img == NULL)
		return (ft_putstr_fd("invalid exit image\n", 2), false);
	pics->collect_img = mlx_xpm_file_to_image(data->mlx, "../asset/collect.xpm",
			&data->img_height, &data->img_width);
	if (pics->collect_img == NULL)
		return (ft_putstr_fd("invalid collect image\n", 2), false);
	pics->player_img = mlx_xpm_file_to_image(data->mlx, "../asset/player.xpm",
			&data->img_height, &data->img_width);
	if (pics->player_img == NULL)
		return (ft_putstr_fd("invalid player image\n", 2), false);
	pics->backg_img = mlx_xpm_file_to_image(data->mlx,
			"../asset/background.xpm", &data->img_height, &data->img_width);
	if (pics->backg_img == NULL)
		return (ft_putstr_fd("invalid background image\n", 2), false);
	return (true);
}

bool	init_pics(t_game *data)
{
	t_pixel *pics;

	pics = malloc(sizeof(t_pixel));
	if (pics == NULL)
		return (NULL);
	if (init_picture(data, pics) == false)
		return (false);
	display_map(data, pics);
	return (true);
}