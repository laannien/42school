/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:37:09 by uheirloo          #+#    #+#             */
/*   Updated: 2019/09/12 17:52:31 by uheirloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void const *s, int c, size_t n)
{
	unsigned char	test;
	unsigned char	*string;
	size_t			i;

	i = 0;
	test = (unsigned char)c;
	string = (unsigned char *)s;
	while (i < n)
	{
		if (string[i] == test)
		{
			return ((void*)(s + i));
		}
		i++;
	}
	return (NULL);
}
