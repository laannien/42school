/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:54:01 by uheirloo          #+#    #+#             */
/*   Updated: 2019/09/12 18:22:55 by uheirloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, void const *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	if (dst == NULL && src == NULL)
	{
		return (NULL);
	}
	i = 0;
	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	while (i < n)
	{
		*(d + i) = *(s + i);
		i++;
	}
	return (d);
}
