/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 22:18:52 by acrucesp          #+#    #+#             */
/*   Updated: 2022/02/15 23:57:27 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h> 

t_cmd	**free_cmds(t_cmd **cmds, int j, int n)
{
	while (--n >= 0)
	{
		j = (cmds[n])->argc;
		ft_lstclear(&(cmds[n])->rdtns, &free_redirections);
		while (--j >= 0)
			free(cmds[n]->argv[j]);
		free(cmds[n]->argv);
		free(cmds[n]);
	}
	free(cmds);
	return (NULL);
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
