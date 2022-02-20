/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:52:37 by manmarti          #+#    #+#             */
/*   Updated: 2022/02/20 13:59:53 by manuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	rdrc_append(char *pathname)
{
	int	fd;

	fd = open(pathname, A_FLGS, F_PERM);
	if (fd == -1)
	{
		perror("open");
		exit(-1);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
}

static void	rdrc_in(char *pathname)
{
	int	fd;

	fd = open(pathname, I_FLGS, F_PERM);
	if (fd == -1)
	{
		perror("open");
		exit(-1);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
}

static void	rdrc_here(char *limit)
{
	int		fd;
	char	*str;

	fd = open(HERE_DOCS, W_FLGS, F_PERM);
	if (fd == -1)
		exit_error("open");
	str = readline("> ");
	while (ft_strncmp(str, limit, ft_strlen(limit) + 1))
	{
		ft_putstr_fd(str, fd);
		ft_putchar_fd('\n', fd);
		free(str);
		str = readline("> ");
		if (!str)
			exit_error("bash");
	}
	free(str);
	close(fd);
	rdrc_in(HERE_DOCS);
}

static void	rdrc_out(char *pathname)
{
	int	fd;

	fd = open(pathname, W_FLGS, F_PERM);
	if (fd == -1)
	{
		perror("open");
		exit(-1);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
}

void	redirects(t_list *rdrc)
{
	while (rdrc != NULL)
	{
		if (!ft_strncmp(((t_rdtns *)rdrc->content)->type, ">>", 3))
			rdrc_append(((t_rdtns *)rdrc->content)->file);
		else if (!ft_strncmp(((t_rdtns *)rdrc->content)->type, "<<", 3))
			rdrc_here(((t_rdtns *)rdrc->content)->file);
		else if (!ft_strncmp(((t_rdtns *)rdrc->content)->type, ">", 2))
			rdrc_out(((t_rdtns *)rdrc->content)->file);
		else if (!ft_strncmp(((t_rdtns *)rdrc->content)->type, "<", 2))
			rdrc_in(((t_rdtns *)rdrc->content)->file);
		rdrc = rdrc->next;
	}
}
