/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relexer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 11:04:30 by manmarti          #+#    #+#             */
/*   Updated: 2022/03/08 16:14:21 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	retokenize(t_cmd **cmd, t_list *aux, int i)
{
	int		j;

	j = 0;
	while (cmd[i]->argv[j])
		free(cmd[i]->argv[j++]);
	free(cmd[i]->argv);
	cmd[i]->argv = ft_calloc(sizeof(char *), ft_lstsize(aux) + 1);
	j = 0;
	while (aux)
	{
		cmd[i]->argv[j++] = ft_strdup(aux->content);
		aux = aux->next;
	}
}

static void	relexer_args(t_cmd **cmds, int i)
{
	int		j;
	t_list	*aux;

	j = -1;
	aux = NULL;
	while (cmds[i]->argv[++j])
	{
		if (cmds[i]->was_exp[j])
			ft_lstadd_back(&aux, minilexer(cmds[i]->argv[j]));
		else
			ft_lstadd_back(&aux, ft_lstnew(ft_strdup(cmds[i]->argv[j])));
	}
	retokenize(cmds, aux, i);
	ft_lstclear(&aux, free);
}

static void	rdrc_error(t_cmd *cmd)
{
	t_list	*rdrc;
	t_rdtns	*error_flag;

	rdrc = cmd->rdtns;
	if (((t_rdtns *)rdrc->content)->type[0] == 'x')
		return ;
	ft_lstclear(&cmd->rdtns, free_redirections);
	error_flag = ft_calloc(sizeof(t_rdtns), 1);
	error_flag->type = ft_strdup("x");
	cmd->rdtns = ft_lstnew(error_flag);
	ft_putendl_fd("Ambiguous redirection", STDERR_FILENO);
}

static void	relexer_rdrc(t_cmd **cmds, t_list *rdrc, int i)
{
	int		j;
	t_list	*aux;

	aux = NULL;
	j = 0;
	while (rdrc)
	{
		if (cmds[i]->rwas_exp[j])
			ft_lstadd_back(&aux, minilexer(((t_rdtns *)rdrc->content)->file));
		else
			ft_lstadd_back(&aux,
				ft_lstnew(ft_strdup(((t_rdtns *)rdrc->content)->file)));
		rdrc = rdrc->next;
		j++;
	}
	if (ft_lstsize(cmds[i]->rdtns) != ft_lstsize(aux))
		rdrc_error(cmds[i]);
	rdrc = aux;
	while (rdrc)
	{
		if (rdrc->content == NULL)
			rdrc_error(cmds[i]);
		rdrc = rdrc->next;
	}
	ft_lstclear(&aux, free);
}

void	relexer(t_cmd **cmds)
{
	int		i;
	t_list	*rdrc;

	i = -1;
	while (cmds[++i])
	{
		relexer_args(cmds, i);
		rdrc = cmds[i]->rdtns;
		relexer_rdrc(cmds, rdrc, i);
	}
}
