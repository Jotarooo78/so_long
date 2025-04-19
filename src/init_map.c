/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:34:19 by armosnie          #+#    #+#             */
/*   Updated: 2025/04/19 17:15:11 by armosnie         ###   ########.fr       */
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
		if (len[0] != '\n' && len[0] != '\0')
			count++;
		free(len);
		len = get_next_line(fd);
	}
	free(len);
	close(fd);
	return (count);
}

bool	check_double_backslash(char *tmp)
{
	int i;

	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == '\n' && tmp[i + 1] == '\n')
			return (true);
		i++;
	}
	return (false);
}

char	*join_map(t_game *mlxs, char *str, int fd)
{
	char	*tmp;
	char	*new_tmp;

	tmp = ft_strdup("");
	if (tmp == NULL)
		return ;
	while (str)
	{
		new_tmp = ft_strjoin(str, tmp);
		if (new_tmp == NULL)
			return (free(str), close(fd), NULL);
		tmp = new_tmp;
		free(str);
		str = get_next_line(fd);
	}
	if (check_double_backslash(tmp) == true)
	{
		free(tmp);
		ft_putstr_fd("invalid fd 1\n", 2);
	}
	return (tmp);
}

bool	init_map(t_game *mlxs, char *filename)
{
	int		size;
	int		fd;
	char	*str;
	char	*tmp;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("invalid fd 1\n", 2), false);
	str = get_next_line(fd);
	tmp = join_map(mlxs, str, fd);
	if (tmp == NULL)
	{
		close(fd);
		exit(EXIT_FAILURE);
	}
	close(fd);
	mlxs->map = ft_split(str, '\n');
	free(tmp);
	if (mlxs->map == NULL)
	{
		free(tmp);
		exit(EXIT_FAILURE);
	}
	if (check_map(mlxs, mlxs->map, size) == false)
		return (false);
	return (true);
}
