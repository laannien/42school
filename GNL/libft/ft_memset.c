/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 13:15:46 by uheirloo          #+#    #+#             */
/*   Updated: 2019/09/13 13:26:52 by uheirloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	val;
	unsigned char	*str;
	size_t			i;

	val = (unsigned char)c;
	str = (unsigned char*)b;
	i = 0;
	while (i < len)
	{
		str[i] = val;
		i++;
	}
	return (b);
}
