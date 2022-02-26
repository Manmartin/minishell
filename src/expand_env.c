/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:32:54 by manmarti          #+#    #+#             */
/*   Updated: 2022/02/26 21:13:10 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	exit_error(char *msg)
{
	perror(msg);
	exit(1);
}

int	select_env(char **s, int i)
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
	aux = ft_substr(str, i, j);
	if (!aux)
		exit_error("malloc");
	env_var = get_env(aux);
	if (!env_var)
		exit_error("malloc");
	free(aux);
	var_len = ft_strlen(env_var);
	*s = append_string(append_string(ft_substr(str, 0, i - 1), env_var),
			ft_substr(str, i + j, ft_strlen(&str[i + j])));
	free(str);
	return (i - 1 + var_len);
}

static char	*make_expanded_str(char **str)
{
	t_flags	flags;
	char	*aux;
	int		i;

	i = 0;
	ft_memset(&flags, 0, sizeof(t_flags));
	aux = *str;
	while (aux[i])
	{
		if (aux[i] == '\'' && !flags.d_qts)
			flags.s_qts = !flags.s_qts;
		else if (aux[i] == '"' && !flags.s_qts)
			flags.d_qts = !flags.d_qts;
		if (aux[i] == '$' && ft_isenv(aux[i + 1]) && !flags.s_qts)
			i = select_env(&aux, i + 1) - 1;
		i++;
	}
	return (aux);
}

void	expand_env(t_cmd **cmds)
{
	int		j;
	t_list	*rdrc;

	while (*cmds)
	{
		j = 0;
		while (cmds[0]->argv[j])
		{
			cmds[0]->argv[j] = make_expanded_str(&cmds[0]->argv[j]);
			quote_remover(&cmds[0]->argv[j]);
			j++;
		}
		rdrc = cmds[0]->rdtns;
		while (rdrc)
		{
			((t_rdtns *)rdrc->content)->file
				= make_expanded_str(&((t_rdtns *)rdrc->content)->file);
			quote_remover(&((t_rdtns *)rdrc->content)->file);
			rdrc = rdrc->next;
		}		
		cmds++;
	}
}
