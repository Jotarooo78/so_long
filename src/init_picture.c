/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_picture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:18:21 by armosnie          #+#    #+#             */
/*   Updated: 2025/04/29 17:04:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_sprite(t_game *data, char c, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->pics.wall_img.img, x
			* 16, y * 16);
	if (c == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->pics.backg_img.img,
			x * 16, y * 16);
	if (c == 'C')
		mlx_put_image_to_window(data->mlx, data->win,
			data->pics.collect_img.img, x * 16, y * 16);
	if (c == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->pics.exit_img.img, x
			* 16, y * 16);
	if (c == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->pics.player_img.img,
			x * 16, y * 16);
}

void	display_map(t_game *data)
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
				put_sprite(data, data->map[y][x], x, y);
			if (data->map[y][x] == '0')
				put_sprite(data, data->map[y][x], x, y);
			if (data->map[y][x] == 'C')
				put_sprite(data, data->map[y][x], x, y);
			if (data->map[y][x] == 'E')
				put_sprite(data, data->map[y][x], x, y);
			if (data->map[y][x] == 'P')
				put_sprite(data, data->map[y][x], x, y);
			x++;
		}
		y++;
	}
}

bool	check_images(t_game *data)
{
	if (data->pics.wall_img.img == NULL)
		return (ft_putstr_fd("Error\nInvalid wall image\n", 2), false);
	if (data->pics.exit_img.img == NULL)
		return (ft_putstr_fd("Error\nInvalid exit image\n", 2), false);
	if (data->pics.collect_img.img == NULL)
		return (ft_putstr_fd("Error\nInvalid collect image\n", 2), false);
	if (data->pics.player_img.img == NULL)
		return (ft_putstr_fd("Error\nInvalid player image\n", 2), false);
	if (data->pics.backg_img.img == NULL)
		return (ft_putstr_fd("Error\nInvalid background image\n", 2), false);
	return (true);
}

void	init_picture(t_game *data)
{
	data->img_height = 16;
	data->img_width = 16;
	data->pics.wall_img.img = mlx_xpm_file_to_image(data->mlx,
			"./asset/wall.xpm", &data->img_height, &data->img_width);
	data->pics.exit_img.img = mlx_xpm_file_to_image(data->mlx,
			"./asset/exit.xpm", &data->img_height, &data->img_width);
	data->pics.collect_img.img = mlx_xpm_file_to_image(data->mlx,
			"./asset/collect.xpm", &data->img_height, &data->img_width);
	data->pics.player_img.img = mlx_xpm_file_to_image(data->mlx,
			"./asset/player.xpm", &data->img_height, &data->img_width);
	data->pics.backg_img.img = mlx_xpm_file_to_image(data->mlx,
			"./asset/background.xpm", &data->img_height, &data->img_width);
}

bool	manage_init_texture(t_game *data)
{
	init_picture(data);
	if (check_images(data) == false)
		return (false);
	display_map(data);
	data->move = -1;
	return (true);
}
