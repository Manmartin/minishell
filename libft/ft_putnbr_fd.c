/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <acrucesp@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 20:46:34 by acrucesp          #+#    #+#             */
/*   Updated: 2021/04/04 20:48:14 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	unsigned int	nn;

	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nn = nb * -1;
	}
	else
		nn = nb;
	if (nn >= 10)
	{
		ft_putnbr_fd(nn / 10, fd);
		ft_putchar_fd((nn % 10) + '0', fd);
	}
	else if (nn >= 0 && nn <= 9)
	{
		ft_putchar_fd(nn + '0', fd);
	}
}
