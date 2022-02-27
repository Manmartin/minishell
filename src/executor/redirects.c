/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:52:37 by manmarti          #+#    #+#             */
/*   Updated: 2022/02/27 12:06:59 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	rdrc_append(char *pathname)
{
	int	fd;

	fd = open(pathname, O_CREAT | O_WRONLY | O_APPEND,
			S_IRUSR | S_IWUSR | S_IWGRP | S_IRGRP | S_IROTH);
	if (fd == -1)
		exit_error("open");
	dup2(fd, STDOUT_FILENO);
	close(fd);
}

static void	rdrc_in(char *pathname)
{
	int	fd;

	fd = open(pathname, O_RDONLY,
			S_IRUSR | S_IWUSR | S_IWGRP | S_IRGRP | S_IROTH);
	if (fd == -1)
		exit_error("open");
	dup2(fd, STDIN_FILENO);
	close(fd);
}

static void	rdrc_here(char *limit)
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
	rdrc_in(file);
	free(file);
}

static void	rdrc_out(char *pathname)
{
	int	fd;

	fd = open(pathname, O_CREAT | O_WRONLY | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IWGRP | S_IRGRP | S_IROTH);
	if (fd == -1)
		exit_error("open");
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
