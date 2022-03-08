/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_rdrc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 20:29:36 by manmarti          #+#    #+#             */
/*   Updated: 2022/03/08 15:34:04 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	expand_heredocs(char **str)
{
	int		i;

	i = 0;
	while ((*str)[i])
	{
		if ((*str)[i] == '$' && ft_isenv((*str)[i + 1]))
			i = select_env(str, i + 1) - 1;
		i++;
	}
}

char	*create_tmpfile(size_t len)
{
	char	*file;
	int		fd;

	fd = open("/dev/urandom", O_RDONLY);
	if (fd == -1)
		exit_error("open");
	file = ft_calloc(len + 1, sizeof(char));
	if (file == NULL)
		exit_error("malloc");
	while (len--)
	{
		read(fd, &file[len], 1);
		if (file[len] < 0)
			file[len] *= -1;
		file[len] = (file[len] % 26) + 'A';
	}
	file = append_string(ft_strdup("/tmp/"), file);
	close(fd);
	if (!access(file, F_OK))
	{
		free(file);
		file = create_tmpfile(len);
	}
	return (file);
}
