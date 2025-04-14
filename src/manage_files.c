/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 15:00:02 by armosnie          #+#    #+#             */
/*   Updated: 2025/04/13 15:00:02 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	open_infile(t_data *data, int i, int *pipe_fd)
{
	int	fd;

	close(pipe_fd[READ]);
	dup2(pipe_fd[WRITE], STDOUT);
	close(pipe_fd[WRITE]);
	fd = open(data->infile, O_RDONLY);
	if (fd == -1)
	{
		ft_error("infile opening error", 1);
	}
	dup2(fd, STDIN);
	close(fd);
}

void	open_outfile(t_data *data, int i, int *pipe_fd)
{
	int	fd;

	close(pipe_fd[READ]);
	close(pipe_fd[WRITE]);
	fd = open(data->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		ft_error("outfile opening error", 1);
	}
	dup2(fd, STDOUT);
	close(fd);
}
