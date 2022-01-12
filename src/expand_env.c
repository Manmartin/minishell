/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:32:54 by manmarti          #+#    #+#             */
/*   Updated: 2022/01/12 16:00:41 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	*append_string(char *s1, char *s2)
{
	char	*new_str;

	if (!s1 || !s2)
	{
		perror("malloc");
		exit(0);
	}
	new_str = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	if (!new_str)
	{
		free_data();
		perror("malloc");
		exit(0);
	}
	return (new_str);
}

static int select_env(char **s, int i)
{
	char	*env_var;
	char	*aux;
	char	*str;
	int		var_len;
	int		j;

	j = 0;
	str = *s;
	while (str[i + j] && ft_isenv(str[i + j]))
		j++;
	if (j == 0)
		aux = ft_strdup("$");
	else
		aux = ft_substr(str, i, j);
	if (!aux)
	{
		free_data();
		perror("malloc");
		exit(0);
	}
	if (j == 0)
		env_var = aux;
	else
		env_var = get_env(aux);
	if (!env_var)
	{
		free_data();
		perror("malloc");
		exit(0);
	}
	var_len = ft_strlen(env_var);
	*s = append_string(append_string(ft_substr(str, 0, i - 1), env_var), ft_substr(str, i + j, ft_strlen(&str[i + j])));
	free(str);
	return (i - 1 + var_len);
}

void	expand_env(t_list *tokens)
{
	char	*aux;
	int 	i;

	i = 0;
	while (tokens)
	{
		aux = tokens->content;
		while(aux[i])
		{
			if (aux[i] == '$')
				i = select_env(&aux, i + 1) - 1;
			i++;
		}
		i = 0;
		tokens->content = aux;
		tokens = tokens->next;
	}
}
