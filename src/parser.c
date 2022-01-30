/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:45:57 by acrucesp          #+#    #+#             */
/*   Updated: 2022/01/30 20:45:27 by acrucesp         ###   ########.fr       */
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
	printf("%i\n", n_nodes);
	return (n_nodes);
}

static int	add_arg(t_list **args, void *str, t_list *tokens)
{
	t_list		*new;
	t_rdnctns	rdctns;

	rdctns.type = ft_strdup((char *)str);
	tokens = tokens->next;
	rdctns.file = ft_strdup((char *)tokens->content);
	//pasar tokens por referencia para asi poder conservar el avance y
	//controlar el error
	new = ft_lstnew((void *)&rdctns);
	if (!new || !str)
		return (0);
	ft_lstadd_back(args, new);
	return (1);
}

void	load_cmd(t_list *tokens, t_cmd **cmds, int i, int j)
{
	char 	**types;
	int		y;
	t_rdnctns temp;

	y = 0;
	types = ft_split(TYPES, ',');
	while (types[y])
	{
		if (ft_strnstr((char *)tokens->content, types[y],
			ft_strlen((char *)tokens->content)))
		{
			add_arg(&(*cmds)->rdctns, types[y], tokens);
			//el siguiente tiene que ser el fichero y si no error syntax
			temp = *(t_rdnctns *)(*cmds)->rdctns->content;
			printf("%s\n", temp.type);
		}
		y++;
	}
	((*cmds)[j]).argv[i] = ft_strdup((char *)tokens->content);
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
	cmds = ft_calloc(sizeof(*cmds), n_pipes + 1);
	while (tokens)
	{
		if (!(cmds[j]).argv)
			(cmds[j]).argv = ft_calloc(sizeof(char *), count_nodes(tokens, i) + 1);
		if (ft_strnstr((char *)tokens->content, "|", 
		ft_strlen((char *)tokens->content)))
		{
			i = 0;
			j++;
		}
		else
		{
			load_cmd(tokens, &cmds, i, j);
			//load struct rdctns
			i++;
		}
		tokens = tokens->next;
	}
	i = 0;
	j = 0;
	while (i < n_pipes + 1)
	{
		while ((cmds[i]).argv[j])
			printf("%i=>%s\n", i, (cmds[i]).argv[j++]);
		j = 0;
		i++;
	}
	//printf("%d\n", n_pipes);
	return (1);
}
