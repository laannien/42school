/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 18:35:59 by uheirloo          #+#    #+#             */
/*   Updated: 2019/09/12 19:55:22 by uheirloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, void const *src, int c, size_t n)
{
	void	*ptr;

	ptr = ft_memchr(src, c, n);
	if (ptr == NULL)
	{
		ft_memcpy(dst, src, n);
		return (NULL);
	}
	ft_memcpy(dst, src, ptr - src + 1);
	return (dst + (ptr - src + 1));
}
