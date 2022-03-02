/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:32:54 by manmarti          #+#    #+#             */
/*   Updated: 2022/03/02 11:34:14 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

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
			make_expand(&((t_rdtns *)rdrc->content)->file,
				&cmds[i]->rwas_exp[++j]);
			rdrc = rdrc->next;
		}
	}
	relexer(cmds);
}
