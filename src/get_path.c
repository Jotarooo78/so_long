/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:54:43 by armosnie          #+#    #+#             */
/*   Updated: 2025/04/13 14:19:27 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	**get_path(char **envp)
{
	char	**path;
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = ft_split(envp[i] + 5, ':');
			if (path == NULL)
				return (NULL);
			return (path);
		}
		i++;
	}
	ft_error("path not found", 1);
	return (NULL);
}

char	*join_slash(char *path, char *cmd_cut)
{
	char	*full_path;
	char	*path_slash;

	path_slash = ft_strjoin(path, "/");
	if (path_slash == NULL)
		return (NULL);
	full_path = ft_strjoin(path_slash, cmd_cut);
	if (full_path == NULL)
		return (NULL);
	free(path_slash);
	return (full_path);
}

bool	exec(char **path, char *cmd_cut, char **cmd, char **envp)
{
	char	*full_path;
	int		i;

	i = 0;
	while (path[i])
	{
		full_path = join_slash(path[i], cmd_cut);
		{
			if (full_path == NULL)
				return (true);
		}
		if (access(full_path, F_OK | X_OK) == 0)
		{
			execve(full_path, cmd, envp);
		}
		free(full_path);
		i++;
	}
	return (false);
}

bool	exe_my_cmd(char *cmd, char **envp, t_data *data)
{
	char	**path;
	char	**cmd_cut;

	cmd_cut = ft_split(cmd, ' ');
	if (cmd_cut == NULL || cmd_cut[0] == NULL)
		return (free_array(cmd_cut), false);
	if (access(cmd_cut[0], F_OK | X_OK) == 0)
		execve(cmd_cut[0], cmd_cut, envp);
	path = get_path(envp);
	if (path == NULL)
		return (free_array(cmd_cut), false);
	exec(path, cmd_cut[0], cmd_cut, envp);
	free_array(path);
	free_array(cmd_cut);
	ft_error("command not found", 127);
	return (false);
}

// int main(int argc, char **argv, char **envp)
// {
//     if (argc > 1)
//     {
//         t_data data = init_variable(argc, argv, envp);
//         exe_my_cmd(argv[1], envp, data);
//     }
//     return (0);
// }