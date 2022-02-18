/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:45:57 by acrucesp          #+#    #+#             */
/*   Updated: 2022/02/15 23:57:30 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int		count_pipes(t_list *tokens)
{
	int	n_cmds;

	n_cmds = 0;
	while (tokens)
	{
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

static int	add_arg(t_list **args, void *str, t_list **tokens)
{
	t_list		*new;
	t_rdtns		*rdtns;

	rdtns = malloc(sizeof(t_rdtns));
	rdtns->type = ft_strdup((char *)str);

	*tokens = (*tokens)->next;
	if (!r_syntax_errors(tokens))
		return (0);
	rdtns->file = ft_strdup((char *)(*tokens)->content);
	new = ft_lstnew(rdtns);
	if (!new || !str)
		return (0);
	ft_lstadd_back(args, new);
	return (1);
}

int	load_cmd(t_list **tokens, t_cmd *cmds, int *i)
{
	char 	**types;
	int		y;
	int		b;
	t_rdtns *temp;

	y = 0;
	b = 1;
	types = ft_split(TYPES, ',');
	while (types[y])
	{
		if (ft_strnstr(types[y], (char *)(*tokens)->content,
			ft_strlen((char *)(*tokens)->content)))
		{
			if (add_arg(&(cmds->rdtns), types[y], tokens))
			{
				temp = (t_rdtns *)cmds->rdtns->content;
				printf("%s\n", temp->type);
				(*i)--;
			}
			else
			{
				free_types(types);
				return (1);
			}
			b = 0;
		}
		y++;
	}
	if (b)
		cmds->argv[*i] = ft_strdup((char *)(*tokens)->content);
	free_types(types);
	return (0);
}

t_cmd	**parser(t_list *tokens)
{
	int		n_pipes;
	int		i;
	int		j;
	int		out;
	t_cmd	**cmds;

	i = 0;
	j = 0;
	out = 0;
	cmds = NULL;
	n_pipes = count_pipes(tokens);
	cmds = ft_calloc(sizeof(*cmds), n_pipes + 1);
	for (int k = 0; k <= n_pipes; k++)
		cmds[k] = ft_calloc(sizeof(t_cmd), 1);
	while (tokens && cmds)
	{
		if (!(cmds[j])->argv)
		{
			(cmds[j])->argv = ft_calloc(sizeof(char *), count_nodes(tokens, i) + 1);
			(cmds[j])->argc = count_nodes(tokens, i) + 1;
		}
		if (ft_strnstr((char *)tokens->content, "|", 
		ft_strlen((char *)tokens->content)))
		{
			if (!p_syntax_errors(tokens, 0))
			{
				free_cmds(cmds, j, n_pipes);
				cmds = NULL;
			}
			i = 0;
			j++;
		}
		else
		{
			if (load_cmd(&tokens, cmds[j], &i))
			{
				free_cmds(cmds, j, n_pipes);
				cmds = NULL;
			}
			i++;
		}
		if (cmds)
			tokens = tokens->next;
	}
	return (cmds);
}
