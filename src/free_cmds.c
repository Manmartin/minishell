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

void	free_cmds(t_cmd **cmds, int j)
{
	while (j > -1)
	{
		ft_lstclear(&(cmds[j])->rdtns, &free_redirections);
		free(cmds[j]->argv);
		j--;
	}
}

void free_redirections(void *redirections)
{
	t_rdtns *aux;

	aux = redirections;
	free(aux->type);
	free(aux->file);
}

void free_types(char **types, int y)
{
	while (y)
		free(types[--y]);
	free(types);
	types = NULL;
}
