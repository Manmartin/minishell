/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:45:57 by acrucesp          #+#    #+#             */
/*   Updated: 2021/12/20 22:59:17 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int		count_pipes(t_list *tokens)
{
	int	n_cmds;

	n_cmds = 0;
	while (tokens)
	{
	//aun tengo que evaluar casos raros estilo echa a| > c como reacciona bash
		if (ft_strnstr((char *)tokens->content, "|", 
		ft_strlen((char *)tokens->content)))
			n_cmds++;
		tokens = tokens->next;
	}
	return (n_cmds);
}

int		count_nodes(t_list *tokens, int positions)
{
	int	n_nodes;
	int	exit;
	int	i;

	n_nodes = 0;
	exit = 0;
	i = 0;
	while (tokens && !exit && positions)
	{
		if (i == positions) 
			exit = 1; 
		i++;
		tokens = tokens->next;
	}
	while (tokens)
	{
		if (ft_strnstr((char *)tokens->content, "|", 
		ft_strlen((char *)tokens->content)))
			return (n_nodes);
		n_nodes++;
		tokens = tokens->next;

	}
	return (n_nodes);
}

t_list	*parser(t_list *tokens)
{
	int		n_pipes;
	int		i;
	int		j;
	int		k;
	t_list	*cmds;
	t_cmd	*cmd;

	i = 0;
	j = 0;
	k = 0;
	cmds = NULL;
	cmd = NULL;
	n_pipes = count_pipes(tokens);
	while (i < n_pipes)
	{
		*cmd->argv = ft_calloc(sizeof(char), count_nodes(tokens, i++));
		while (tokens && !k)
		{
			if (ft_strnstr((char *)tokens->content, "|", 
			ft_strlen((char *)tokens->content)))
			{
				k = 1;
				tokens = tokens->next;
			}
			cmd->argv[j++] = (char *)tokens->content; 
			tokens = tokens->next;
		}
		if (!cmds)
			cmds = ft_lstnew(cmd);
		k = 0;
	}

	printf("%d\n", n_pipes);
	return (cmds);
}
