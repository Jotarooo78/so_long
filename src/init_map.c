/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:34:19 by armosnie          #+#    #+#             */
/*   Updated: 2025/05/01 15:27:48 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

bool	check_double_backslash(char *tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == '\n' && tmp[i + 1] == '\n')
			return (true);
		i++;
	}
	return (false);
}

char	*join_map(char *str, int fd)
{
	char	*tmp;
	char	*new_tmp;

	tmp = ft_strdup("");
	if (tmp == NULL)
		return (NULL);
	while (str)
	{
		new_tmp = ft_strjoin(tmp, str);
		if (new_tmp == NULL)
			return (free(str), free(tmp), close(fd), NULL);
		free(tmp);
		tmp = new_tmp;
		free(str);
		if (ft_strlen(tmp) > 10000)
			return (free(tmp), ft_putstr_fd("Error\ntoo big map\n", 2), NULL);
		str = get_next_line(fd);
	}
	if (check_double_backslash(tmp) == true)
	{
		free(tmp);
		ft_putstr_fd("Error\ninvalid fd 1\n", 2);
		return (NULL);
	}
	return (tmp);
}

bool	init_map(t_game *data, char *filename)
{
	int		fd;
	char	*str;
	char	*tmp;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Error\ninvalid fd 1\n", 2), false);
	str = get_next_line(fd);
	tmp = join_map(str, fd);
	if (tmp == NULL)
	{
		close(fd);
		return (false);
	}
	close(fd);
	data->map = ft_split(tmp, '\n');
	free(tmp);
	if (data->map == NULL)
		return (false);
	if (check_map(data) == false)
		return (free_array(data->map), false);
	return (true);
}
