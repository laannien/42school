/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <uheirloo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 11:21:43 by uheirloo          #+#    #+#             */
/*   Updated: 2019/09/18 12:45:50 by uheirloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_return(unsigned long nb, int sign)
{
	if (nb > 9223372036854775807)
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

static int		ft_sign(char const *str)
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

int				ft_atoi(char const *str)
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
