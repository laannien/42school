/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 11:21:43 by uheirloo          #+#    #+#             */
/*   Updated: 2019/09/14 12:56:59 by uheirloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_return(unsigned long nb, int sign)
{
	if (nb > 2147483648)
	{
		if (sign == 1)
		{
			return (-1);
		}
		else
		{
			return (0);
		}
	}
	return ((int)nb * sign);
}

int		ft_sign(char const *str)
{
	while (ft_isspace(*str) != 0)
	{
		str++;
	}
	if (*str == '-')
	{
		return (-1);
	}
	return (1);
}

int		ft_atoi(char const *str)
{
	unsigned long	result;
	int				sign;

	sign = ft_sign(str);
	result = 0;
	while (ft_isspace(*str) != 0)
	{
		str++;
	}
	while (*str)
	{
		if (*str == '-' || *str == '+')
		{
			str++;
		}
		while (*str >= '0' && *str <= '9')
		{
			result = result * 10 + (*str - '0');
			str++;
		}
		break ;
	}
	return (ft_return(result, sign));
}
