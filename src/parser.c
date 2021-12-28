/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:45:57 by acrucesp          #+#    #+#             */
/*   Updated: 2021/12/28 21:58:50 by acrucesp         ###   ########.fr       */
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

int	parser(t_list *tokens)
{
	int		n_pipes;
	int		i;
	int		j;
	t_cmd	*cmds;

	i = 0;
	j = 0;
	cmds = NULL;
	n_pipes = count_pipes(tokens);
	cmds = ft_calloc(sizeof(t_cmd), n_pipes);
	while (tokens)
	{
		if (!(cmds[j]).argv)
			(cmds[j]).argv = ft_calloc(sizeof(char *), count_nodes(tokens, i));
		if (!ft_strncmp((char *)tokens->content, "|", 
		ft_strlen((char *)tokens->content)))
		{
			i = 0;
			j++;
		}
		else
		{
			(cmds[j]).argv[i] = ft_strdup((char *)tokens->content);
			i++;
		}
		tokens = tokens->next;
	}
	printf("=>%s\n", (cmds[0]).argv[0]);
	printf("=>%s\n", (cmds[1]).argv[0]);

	printf("%d\n", n_pipes);
	return (1);
}
