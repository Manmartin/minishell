/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <acrucesp@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 17:54:55 by acrucesp          #+#    #+#             */
/*   Updated: 2021/04/05 18:09:51 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*lst_match;
	int		i;

	i = 0;
	while (*s)
	{
		if (*s++ == c)
		{
			lst_match = (char *)s;
			i++;
		}
		else if (c == 0 && *s == 0)
			return ((char *)s);
	}
	if (i == 0 && c == 0)
		return ((char *)s);
	else if (i == 0)
		return (0);
	return (--lst_match);
}
