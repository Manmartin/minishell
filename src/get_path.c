/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:21:10 by manmarti          #+#    #+#             */
/*   Updated: 2022/01/25 17:51:43 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.c>

static void	get_dir(const char *path)
{
	DIR				*dir;
	struct dirent	*dirp;
	
	dir = opendir(paths[i]);	
	while ((dirp = readdir(dir)) != NULL)
	{
		if (!ft_strncmp(dirp->d_name, cmd, 256))
		{	
			closedir(dir);
			return (ft_strdup());
		}
	}
	closedir(dir);
}

char	*get_path(const char *const cmd)
{
	char	**paths;
	char	*path;
	int		i;

	i = 0;
	if (cmd[0] == '/' || !ft_strncmp(cmd, "./", 2) || !ft_strncmp(cmd, "../", 3))
		return (ft_strdup(cmd));
	path = get_env("PATH");
	paths = ft_split(path, ':');
	if (paths == NULL || path == NULL)
		exit_error("malloc");
	while (paths[i])
	{
		path = get_dir();
	}
	i = 0;
	while (paths[i])
		free(paths[i++]);
	free(paths);
	return (path);
}

