/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 19:34:24 by manmarti          #+#    #+#             */
/*   Updated: 2022/03/01 12:05:38 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_cmd	**alloc_cmds(int n_pipes)
{
	t_cmd	**cmds;
	int		i;

	i = 0;
	cmds = ft_calloc(sizeof(*cmds), n_pipes + 2);
	while (i <= n_pipes)
		cmds[i++] = ft_calloc(sizeof(t_cmd), 1);
	cmds[i] = NULL;
	return (cmds);
}

void	alloc_cmd(t_cmd ***cmds, int i, int j, t_list *tokens)
{
	if (!(*cmds)[j]->argv)
	{
		(*cmds)[j]->argv = ft_calloc(sizeof(char *),
				count_nodes(tokens, i) + 1);
		(*cmds)[j]->argc = count_nodes(tokens, i) + 1;
	}
}

void	load_cmds(t_list **tokens, t_cmd ***cmds, int (*i)[2], int n_pipes)
{
	if (ft_strnstr((char *)(*tokens)->content, "|",
		ft_strlen((char *)(*tokens)->content)))
	{
		if ((*i)[0] == 0 && !p_syntax_errors((*tokens), 1))
			(*cmds) = free_cmds(*cmds, (*i)[1], n_pipes + 1);
		else if (!p_syntax_errors((*tokens), 0))
			(*cmds) = free_cmds(*cmds, (*i)[1], n_pipes + 1);
		(*i)[0] = 0;
		(*i)[1]++;
	}
	else
	{
		if (load_cmd(tokens, (*cmds)[(*i)[1]], &((*i)[0])))
			*cmds = free_cmds(*cmds, (*i)[1], n_pipes + 1);
		(*i)[0]++;
	}
}
