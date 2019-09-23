/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <uheirloo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:18:20 by uheirloo          #+#    #+#             */
/*   Updated: 2019/09/17 18:10:53 by uheirloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_check_min_int(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2", fd);
		n = 147483648;
	}
	else
	{
		ft_putchar_fd('-', fd);
		n = n * -1;
	}
	return (n);
}

void			ft_putnbr_fd(int n, int fd)
{
	char symb;

	if (n < 0)
	{
		n = ft_check_min_int(n, fd);
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	symb = n % 10 + '0';
	ft_putchar_fd(symb, fd);
}
