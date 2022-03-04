/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:32:54 by manmarti          #+#    #+#             */
/*   Updated: 2022/03/04 12:03:09 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	remove_all_quotes(t_cmd **cmds)
{
	int			i;
	int			j;
	t_list	*rdrc;
	
	i = -1;
	while (cmds[++i])
	{
		j = -1;
		while (cmds[i]->argv[++j])
			quote_remover(&cmds[i]->argv[j]);
		rdrc = cmds[i]->rdtns;
		while (rdrc)
		{
			quote_remover(&((t_rdtns *)rdrc->content)->file);
			rdrc = rdrc->next;
		}
	}
}

void	expand_env(t_cmd **cmds)
{
	int		j;
	int		i;
	t_list	*rdrc;

	i = -1;
	while (cmds[++i])
	{
		j = -1;
		cmds[i]->was_exp = ft_calloc(cmds[i]->argc + 1, sizeof(char));
		while (cmds[i]->argv[++j])
			make_expand(&cmds[i]->argv[j], &cmds[i]->was_exp[j]);
		rdrc = cmds[i]->rdtns;
		cmds[i]->rwas_exp = ft_calloc(ft_lstsize(rdrc) + 1, sizeof(char));
		j = -1;
		while (rdrc)
		{
			if (ft_strncmp(((t_rdtns *)rdrc->content)->type, "<<", 3))
				make_expand(&((t_rdtns *)rdrc->content)->file,
					&cmds[i]->rwas_exp[++j]);
			rdrc = rdrc->next;
		}
	}
	relexer(cmds);
	remove_all_quotes(cmds);
}
