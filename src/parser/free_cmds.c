/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 22:18:52 by acrucesp          #+#    #+#             */
/*   Updated: 2022/03/01 21:33:52 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h> 

t_cmd	**free_cmds(t_cmd **cmds, int j, int n)
{
	while (--n >= 0 && cmds)
	{
		j = (cmds[n])->argc;
		ft_lstclear(&(cmds[n])->rdtns, &free_redirections);
		while (--j >= 0)
			free(cmds[n]->argv[j]);
		free(cmds[n]->argv);
		free(cmds[n]);
	}
	free(cmds);
	g_data.n_cmd = 0;
	return (NULL);
}

void	free_all_cmds(t_cmd **cmds)
{
	int	i;
	int	j;

	i = 0;
	while (cmds[i])
	{
		j = 0;
		ft_lstclear(&cmds[i]->rdtns, free_redirections);
		while (cmds[i]->argv[j])
			free(cmds[i]->argv[j++]);
		if (cmds[i]->pathname)
			free(cmds[i]->pathname);
		free(cmds[i]->was_exp);
		free(cmds[i]->rwas_exp);
		free(cmds[i]->argv);
		free(cmds[i++]);
	}
	free(cmds);
	g_data.n_cmd = 0;
}

void	free_redirections(void *redirections)
{
	t_rdtns	*aux;

	aux = redirections;
	free(aux->type);
	free(aux->file);
	free(aux);
}

int	free_types(char **types)
{
	int	y;

	y = 4;
	while (--y >= 0)
		free(types[y]);
	free(types);
	types = NULL;
	return (1);
}

t_list	*clean_args(t_list **args)
{
	ft_lstclear(args, free);
	free_data();
	perror("lexer");
	exit(0);
}
