/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:52:37 by manmarti          #+#    #+#             */
/*   Updated: 2022/02/16 20:01:11 by manuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static	int rdrc_append(char *pathname)
{
	int	fd;
	fd = open(pathname, A_FLGS, F_PERM);
	if (fd == -1)
	{
		perror("fd");
		exit(-1);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}

static int	rdrc_out(char *pathname)
{
	int	fd;

	fd = open(pathname, W_FLGS, F_PERM);
	if (fd == -1)
	{
		perror("fd");
		exit(-1);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}

static int	rdrc_in(char *pathname)
{
	int	fd;

	fd = open(pathname, I_FLGS, F_PERM);
	if (fd == -1)
	{
		perror("fd");
		exit(-1);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (0);
}

void    redirects(t_list *rdrc)
{
	int	status;

	status = 0;
    while (rdrc != NULL)
    {
        if (!ft_strncmp(((t_rdtns *)rdrc->content)->type, ">>", 3))
			status = rdrc_append(((t_rdtns *)rdrc->content)->file);
        else if (!ft_strncmp(((t_rdtns *)rdrc->content)->type, ">", 2))
			status = rdrc_out(((t_rdtns *)rdrc->content)->file);
		else if (!ft_strncmp(((t_rdtns *)rdrc->content)->type, "<", 2))
			status = rdrc_in(((t_rdtns *)rdrc->content)->file);
		rdrc = rdrc->next;
    }
	if (status != 0)
	{
		ft_putstr_fd("Bad redirection\n", 2);
		exit(1);
	}
}
