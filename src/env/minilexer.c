/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilexer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 00:38:25 by manmarti          #+#    #+#             */
/*   Updated: 2022/03/09 20:42:05 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 *	lexer:
 *		receive a string as argument an return a linked list of strings for
 *		parser
 */

static int	add_arg(t_list **args, void *str)
{
	t_list	*new;

	new = ft_lstnew(str);
	if (!new || !str)
		return (0);
	ft_lstadd_back(args, new);
	return (1);
}

static const char	*make_arg(const char *line, t_flags *flags)
{
	while (*line)
	{
		if (*line == '\'' && !flags->d_qts)
		{
			flags->s_qts = !flags->s_qts;
			if (!flags->s_qts && line[1] == ' ')
			{
				line++;
				break ;
			}
		}
		else if (*line == '"' && !flags->s_qts)
		{
			flags->d_qts = !flags->d_qts;
			if (!flags->d_qts && line[1] == ' ')
			{
				line++;
				break ;
			}
		}
		if (!flags->s_qts && !flags->d_qts && *line == ' ')
			break ;
		line++;
	}
	return (line);
}

static const char	*check_instructions(const char *line, t_list **args)
{
	char	*str;

	str = NULL;
	while (ft_isforshell(*line))
	{
		if (*line == '|')
			str = "|";
		else if (ft_strncmp(line, ">>", 2) == 0)
			str = ">>";
		else if (ft_strncmp(line, "<<", 2) == 0)
			str = "<<";
		else if (*line == '<')
			str = "<";
		else if (*line == '>')
			str = ">";
		if (str)
		{
			if (!(add_arg(args, ft_strdup(str))))
				return (0);
			return (line + ft_strlen(str));
		}
		line++;
	}
	return (line);
}

t_list	*minilexer(const char *line)
{
	char const	*init;
	t_list		*args;
	t_flags		flags;

	args = NULL;
	ft_memset(&flags, 0, sizeof(t_flags));
	while (*line)
	{
		init = line;
		line = make_arg(line, &flags);
		if (line != init)
			if (!(add_arg(&args, ft_substr(init, 0, line - init))))
				clean_args(&args);
		line = check_instructions(line, &args);
	}
	return (args);
}
