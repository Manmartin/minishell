/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:21:10 by manmarti          #+#    #+#             */
/*   Updated: 2022/02/20 18:08:31 by manuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	*create_path(const char *path, const char *cmd)
{
	char	*aux;
	char	*cmd_path;

	aux = ft_strjoin(path, "/");
	if (aux == NULL)
		exit_error("malloc");
	cmd_path = ft_strjoin(aux, cmd);
	free(aux);
	if (cmd_path == NULL)
		exit_error("malloc");
	return (cmd_path);
}

static char	*get_dir(const char *path, const char *cmd)
{
	DIR				*dir;
	struct dirent	*dirp;
	char			*aux;

	dir = opendir(path);
	if (dir == NULL)
		return (NULL);
	dirp = readdir(dir);
	while (dirp != NULL)
	{
		if (!ft_strncmp(dirp->d_name, cmd, ft_strlen(dirp->d_name) + 1))
		{
			aux = create_path(path, cmd);
			if (!access(aux, X_OK))
				return (aux);
			free(aux);
		}
		dirp = readdir(dir);
	}
	closedir(dir);
	return (NULL);
}

char	*get_path(const char *const cmd)
{
	char	**paths;
	char	*path;
	int		i;

	i = 0;
	if (cmd[0] == '/' || !ft_strncmp(cmd, "./", 2)
		|| !ft_strncmp(cmd, "../", 3))
		return (ft_strdup(cmd));
	path = get_env("PATH");
	paths = ft_split(path, ':');
	if (paths == NULL || path == NULL)
		exit_error("malloc");
	free(path);
	path = NULL;
	while (paths[i] && path == NULL)
		path = get_dir(paths[i++], cmd);
	i = 0;
	while (paths[i])
		free(paths[i++]);
	free(paths);
	return (path);
}
