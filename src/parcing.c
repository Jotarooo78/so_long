/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:34:19 by armosnie          #+#    #+#             */
/*   Updated: 2025/04/18 14:50:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	grid_size(int fd)
{
	char	*len;
	int		count;

	count = 0;
	len = get_next_line(fd);
	while (len != NULL)
	{
		free(len);
		count++;
		len = get_next_line(fd);
	}
	close(fd);
	return (count);
}

char	**fill_map(char **map, int size, int fd)
{
	char	*line;
	int		i;

	i = 0;
	while (i < size)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			free_array(map);
			return (NULL);
		}
		map[i] = ft_strdup(line);
		free(line);
		if (map[i] == NULL)
		{
			free_array(map);
			return (NULL);
		}
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

bool	init_map(t_game *mlxs, char *filename)
{
	int		size;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("invalid fd 1\n", 2), false);
	size = grid_size(fd);
	mlxs->map = malloc(sizeof(char *) * (size + 1));
	if (mlxs->map == NULL)
		return (ft_putstr_fd("map malloc failed\n", 2), false);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("invalid fd 2\n", 2), false);
	mlxs->map = fill_map(mlxs->map, size, fd);
	if (!mlxs->map)
		return (ft_putstr_fd("map doesn't exist\n", 2), false);
	if (check_map(mlxs->map, size) == false)
		return (false);
	return (true);
}
