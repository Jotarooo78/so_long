/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:19:35 by armosnie          #+#    #+#             */
/*   Updated: 2025/04/13 18:21:37 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	call_child(t_data *data, int *pipe_fd, int i)
{
	if (i == 0)
		open_infile(data, i, pipe_fd);
	else if (i == data->n_cmd - 1)
		open_outfile(data, i, pipe_fd);
	else
	{
		close(pipe_fd[READ]);
		dup2(pipe_fd[WRITE], STDOUT);
		close(pipe_fd[WRITE]);
	}
	exe_my_cmd(data->cmd[i], data->envp, data);
}

void	call_parent(t_data *data, int *pipe_fd)
{
	close(pipe_fd[WRITE]);
	dup2(pipe_fd[READ], STDIN);
	close(pipe_fd[READ]);
}

void	wait_child(void)
{
	while (wait(NULL) > 0)
		;
}

void	pipe_function(t_data *data)
{
	pid_t	pid;
	int		i;
	int		pipe_fd[2];

	i = 0;
	while (data->cmd[i] != NULL)
	{
		if (!(i == data->n_cmd -1) && pipe(pipe_fd) == -1)
			ft_error("pipe error", 1);
		pid = fork();
		if (pid == -1)
			(ft_error("fork error", 1));
		if (pid == 0)
			call_child(data, pipe_fd, i);
		else
			call_parent(data, pipe_fd);
		i++;
	}
	close(STDIN);
	wait_child();
}
