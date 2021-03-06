/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:52:37 by manmarti          #+#    #+#             */
/*   Updated: 2022/03/02 12:54:10 by manmarti         ###   ########.fr       */
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
		if (((t_rdtns *)rdrc->content)->type[0] == 'x')
			exit(1);
		else if (!ft_strncmp(((t_rdtns *)rdrc->content)->type, ">>", 3))
			rdrc_append(((t_rdtns *)rdrc->content)->file);
		else if (!ft_strncmp(((t_rdtns *)rdrc->content)->type, "<<", 3))
			rdrc_in(((t_rdtns *)rdrc->content)->file);
		else if (!ft_strncmp(((t_rdtns *)rdrc->content)->type, ">", 2))
			rdrc_out(((t_rdtns *)rdrc->content)->file);
		else if (!ft_strncmp(((t_rdtns *)rdrc->content)->type, "<", 2))
			rdrc_in(((t_rdtns *)rdrc->content)->file);
		rdrc = rdrc->next;
	}
}
