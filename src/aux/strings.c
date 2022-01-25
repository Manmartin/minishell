/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:17:01 by manmarti          #+#    #+#             */
/*   Updated: 2022/01/20 14:21:58 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*char_append(char *str1, const char c)
{
	char	*aux;
	char	c_aux[2];

	aux = str1;
	c_aux[0] = c;
	c_aux[1] = 0;
	str1 = ft_strjoin(str1, c_aux);
	free(aux);
	return (str1);
}

char	*append_string(char *s1, char *s2)
{
	char	*new_str;

	if (!s1 || !s2)
		exit_error("malloc");
	new_str = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	if (!new_str)
		exit_error("malloc");
	return (new_str);
}
