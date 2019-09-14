/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 13:07:29 by uheirloo          #+#    #+#             */
/*   Updated: 2019/09/14 14:23:05 by uheirloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_size(int n)
{
	int i;

	i = 1;
	if (n <= 0)
	{
		i++;
	}
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;
	long	tmp;

	tmp = (long)n;
	tmp = tmp < 0 ? tmp * -1 : tmp * 1;
	len = ft_size(n);
	result = (char*)malloc(sizeof(char) * len);
	if (!result)
		return (0);
	result[--len] = '\0';
	while (--len >= 0)
	{
		if (n < 0 && len == 0)
			result[len] = '-';
		else
		{
			result[len] = tmp % 10 + '0';
			tmp = tmp / 10;
		}
	}
	return (result);
}
