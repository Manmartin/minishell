/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredocs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:20:47 by manmarti          #+#    #+#             */
/*   Updated: 2022/02/28 18:46:11 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	heredocs(t_list	*rdrc, char *limit)
{
	int		fd;
	char	*str;
	char	*file;

	file = create_tmpfile(10);
	fd = open(file, O_CREAT | O_WRONLY | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IWGRP | S_IRGRP | S_IROTH);
	if (fd == -1)
		exit_error("open");
	str = readline("> ");
	while (str && ft_strncmp(str, limit, ft_strlen(limit) + 1))
	{
		expand_heredocs(&str);
		ft_putendl_fd(str, fd);
		free(str);
		str = readline("> ");
	}
	if (!str)
		exit_shell_error("Warning: EOF in heredocs", -1);
	free(str);
	close(fd);
	free(((t_rdtns *)rdrc->content)->file);
	((t_rdtns *)rdrc->content)->file = file;
}

int	make_heredocs(t_cmd **cmds)
{
	int		i;
	t_list	*aux;

	i = -1;
	signal(SIGINT, heredocs_signals);
	signal(SIGQUIT, heredocs_signals);
	while (cmds[++i] != NULL)
	{
		aux = cmds[i]->rdtns;
		while (aux != NULL)
		{
			if (!ft_strncmp(((t_rdtns *)aux->content)->type, "<<", 3))
				heredocs(aux, ((t_rdtns *)aux->content)->file);
			aux = aux->next;
		}
	}
	return (1);
}
