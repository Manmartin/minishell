/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <acrucesp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 20:49:12 by acrucesp          #+#    #+#             */
/*   Updated: 2021/05/04 18:54:57 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_itoa_base(long long unsigned int n, int base, char *elm_base)
{
	long long int	nn;
	char			*ret;
	int				i;

	i = ft_ndigit(n, base);
	if (n < 0)
	{
		nn = -n;
		i++;
	}
	else
		nn = n;
	if (nn == 0)
		nn = -1;
	ret = ft_calloc(sizeof(char), i + 1);
	*(ret + i) = '\0';
	while (nn > 0)
	{
		ret[--i] = elm_base[nn % base];
		nn = nn / base;
	}
	if (nn == -1)
		*ret = '0';
	return (ret);
}
