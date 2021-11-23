/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:05:49 by manmarti          #+#    #+#             */
/*   Updated: 2021/11/23 18:06:51 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	*addchar(char *str1, const char c)
{
	char	*aux;
	char	*c_aux;

	aux = str1;
	c_aux = ft_calloc(2, sizeof(char));
	if (c_aux == NULL)
		return (NULL);
	c_aux[0] = c;
	str1 = ft_strjoin(str1, c_aux);
	free(aux);
	free(c_aux);
	return (str1);
}

static char	*str_append(char *str1, const char *str2)
{
	char	*aux;

	aux = str1;
	str1 = ft_strjoin(str1, str2);
	free(aux);
	return (str1);
}

char	*get_prompt(void)
{
	char	*template;
	char	*prompt;

	template = PROMPT;
	prompt = (char *)ft_calloc(1, sizeof(char));
	if (prompt == NULL)
		exit(-1);
	while (*template)
	{
		if (*template == '-')
		{
			if (*(++template) == 'u')
				prompt = str_append(prompt, getenv("USER"));
			else if (*template == 'p')
				prompt = str_append(prompt, getenv("PWD"));
			else if (*template == '-')
				prompt = str_append(prompt, "-");
			template++;
		}
		else
			prompt = addchar(prompt, *(template++));
		if (prompt == NULL)
			exit(-1);
	}
	return (prompt);
}
