/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:47:56 by armosnie          #+#    #+#             */
/*   Updated: 2025/04/13 14:18:33 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define READ 0
# define WRITE 1

typedef struct s_data
{
	int		n_cmd;
	char	**cmd;
	char	**envp;
	char	*infile;
	char	*outfile;

}			t_data;

// parcing functions

bool		init_variable(int argc, char **argv, char **envp, t_data *data);
void		free_array(char **split);
void		ft_error(char *str, int code_error);
void		pipe_function(t_data *data);
void		open_infile(t_data *data, int i, int *pipe_fd);
void		open_outfile(t_data *data, int i, int *pipe_fd);
bool		exe_my_cmd(char *cmd, char **envp, t_data *data);

#endif