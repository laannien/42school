/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:10:59 by uheirloo          #+#    #+#             */
/*   Updated: 2019/09/12 17:28:02 by uheirloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isspace(int c)
{
	unsigned char test;

	test = (unsigned char)c;
	if (test == '\t' || test == '\n' || test == '\v' || test == '\f' || \
		test == '\r' || test == ' ')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
