/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:21:10 by manmarti          #+#    #+#             */
/*   Updated: 2022/01/26 12:57:07 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

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
		// Hace falta manejar errores de opendir y de readdir();
		if (!ft_strncmp(dirp->d_name, cmd, 256))
		{
			aux = ft_strdup(path);
			if (path == NULL)
				exit(1);
			closedir(dir);
			return (aux);
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
	path = NULL;
	while (paths[i] && path == NULL)
		path = get_dir(paths[i++], cmd);
	i = 0;
	while (paths[i])
		free(paths[i++]);
	free(paths);
	return (path);
}
