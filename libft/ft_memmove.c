/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 11:40:49 by uheirloo          #+#    #+#             */
/*   Updated: 2019/09/13 12:40:25 by uheirloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, void const *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;
	
	if (src == 0 && dst == 0)
	{
		return (dst);
	}
	i = 0;
	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	while (i < len)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
