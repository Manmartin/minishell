/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <acrucesp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 00:09:38 by acrucesp          #+#    #+#             */
/*   Updated: 2022/03/09 20:09:01 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	free_env(void)
{
	int	i;

	i = -1;
	while (g_data.env[++i])
		free(g_data.env[i]);
	free(g_data.env);
	return (1);
}

/*	get_env return value of a env variable "str"
 * 		-If that variable does not exist, return a empty string
 * 		-If malloc fails, return 0
 */

char	*get_env(const char *const str)
{
	int		i;
	size_t	sz;

	i = 0;
	sz = ft_strlen(str);
	while (g_data.env[i])
	{
		if (ft_strncmp(g_data.env[i], str, sz) == 0
			&& g_data.env[i][sz] == '=')
			return (ft_substr(g_data.env[i], sz + 1,
					ft_strlen(&g_data.env[i][sz + 1])));
		i++;
	}
	return (ft_strdup(""));
}

static void	set_minienv(void)
{
	char	**basics;
	char	*path;
	int		size;

	basics = ft_calloc(6, sizeof(char *));
	g_data.env = basics;
	if (basics == NULL)
		exit_error("calloc");
	g_data.sz_env = 6;
	basics[0] = ft_strdup("PATH=/bin");
	size = 4096;
	path = ft_calloc(sizeof(char), size);
	path = getcwd(path, size);
	set_env(ft_strdup("PWD"), path);
}

void	init_env(char **env)
{
	char	**tmp_env;

	g_data.sz_env = 0;
	while (env[g_data.sz_env])
		g_data.sz_env++;
	g_data.sz_env *= 2;
	if (g_data.sz_env == 0)
		return (set_minienv());
	g_data.env = ft_calloc(g_data.sz_env, sizeof(char *));
	if (!g_data.env)
		exit_error("malloc");
	tmp_env = g_data.env;
	while (*env)
	{
		*tmp_env = ft_strdup(*env++);
		if (!*tmp_env && free_env())
		{
			perror("init_env");
			exit(0);
		}
		tmp_env++;
	}
}
