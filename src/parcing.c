/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:34:19 by armosnie          #+#    #+#             */
/*   Updated: 2025/04/16 17:56:15 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	grid_size(int fd)
{
	char	*len;
	int		count;

	count = 1;
	len = get_next_line(fd);
	while (len != NULL)
	{
		free(len);
		len = get_next_line(fd);
		count++;
	}
	close(fd);
	return (count);
}

char	**fill_map(char *filename, int size, int fd)
{
	char	**map;
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		map[i] = ft_strdup(line);
		if (map[i] == NULL)
		{
			free_array(map);
			return (NULL);
		}
		free(line);
		i++;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

bool	init_map(t_game *mlxs, char *filename)
{
	char	**map;
	int		size;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (false);
	size = grid_size(fd);
	map = malloc(sizeof(char *) * (size + 1));
	if (map == NULL)
		return (false);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (false);
	map = fill_map(filename, size, fd);
    mlxs->map = map;
    check_map(mlxs);
}
