/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ndigit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <acrucesp@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 17:43:22 by acrucesp          #+#    #+#             */
/*   Updated: 2021/05/02 19:04:37 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int	ft_ndigit(long long int n, long long unsigned int base)
{
	long long unsigned int		n_dgt;

	n_dgt = 1;
	if (n < 0)
		n = -n;
	if (n == 0)
		return (1);
	while (n >= ft_power(base, n_dgt))
		n_dgt++;
	return (n_dgt);
}
