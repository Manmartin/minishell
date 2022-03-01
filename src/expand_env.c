/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:32:54 by manmarti          #+#    #+#             */
/*   Updated: 2022/03/01 23:54:33 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

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

void	retokenize(t_cmd **cmd, t_list *aux, int i)
{
	int		j;

	j = 0;
	while (cmd[i]->argv[j])
		free(cmd[i]->argv[j++]);
	free(cmd[i]->argv);
	cmd[i]->argv = ft_calloc(sizeof(char *), ft_lstsize(aux) + 1);
	j = 0;
	while (aux)
	{
		cmd[i]->argv[j++] = ft_strdup(aux->content);
		aux = aux->next;
	}

}

int	relexer(t_cmd **cmds)
{
	int		i;
	int		j;
	t_list	*n;
	t_list	*aux;
	t_list	*rdrc;

	aux = NULL;
	i = -1;
	while (cmds[++i])
	{
		j = 0;
		while (cmds[i]->argv[j])
		{
			if (cmds[i]->was_exp[j])
				ft_lstadd_back(&aux, lexer(cmds[i]->argv[j]));
			else
				ft_lstadd_back(&aux, ft_lstnew(ft_strdup(cmds[i]->argv[j])));
			j++;
		}
		retokenize(cmds, aux, i);
		ft_lstclear(&aux, free);
		aux = NULL;
		rdrc = cmds[i]->rdtns;
		j = 0;
		while (rdrc)
		{
			if (cmds[i]->rwas_exp[j])
				ft_lstadd_back(&aux, lexer(((t_rdtns *)rdrc->content)->file));
			else
				ft_lstadd_back(&aux, ft_lstnew(ft_strdup(((t_rdtns *)rdrc->content)->file)));
			rdrc = rdrc->next;
			j++;
		}
		n = aux;
		while (n)
		{
			if (n->content == NULL)
			{
				ft_putendl_fd("Ambiguous redirecs", STDERR_FILENO);
				return (0);
			}	
			n = n->next;
		}
		if (ft_lstsize(cmds[i]->rdtns) != ft_lstsize(aux))
		{
			ft_putendl_fd("Ambiguous redirecs", STDERR_FILENO);
			return (0);
		}
		ft_lstclear(&aux, free);
		aux = NULL;
	}
	return (1);
}

int	expand_env(t_cmd **cmds)
{
	int		j;
	int		i;
	t_list	*rdrc;
	char	*aux;
	
	i = -1;
	while (cmds[++i])
	{
		j = 0;
		cmds[i]->was_exp = ft_calloc(cmds[i]->argc + 1, sizeof(char));
		while (cmds[i]->argv[j])
		{
			aux = ft_strdup(cmds[i]->argv[j]);
			cmds[i]->argv[j] = make_expanded_str(&cmds[i]->argv[j]);
			if (ft_strncmp(aux, cmds[i]->argv[j], ft_strlen(aux) + 1))
				cmds[i]->was_exp[j] = 1;
			free(aux);
			quote_remover(&cmds[i]->argv[j]);
			j++;
		}
		rdrc = cmds[i]->rdtns;
		cmds[i]->rwas_exp = ft_calloc(ft_lstsize(rdrc) + 1, sizeof(char));
		j = 0;
		while (rdrc)
		{
			aux = ft_strdup(((t_rdtns *)rdrc->content)->file);
			((t_rdtns *)rdrc->content)->file
				= make_expanded_str(&((t_rdtns *)rdrc->content)->file);
			if (ft_strncmp(aux, ((t_rdtns *)rdrc->content)->file, ft_strlen(aux) + 1))
				cmds[i]->rwas_exp[j] = 1;
			j++;
			free(aux);
			quote_remover(&((t_rdtns *)rdrc->content)->file);
			rdrc = rdrc->next;
		}
	}
	return (relexer(cmds));
}
