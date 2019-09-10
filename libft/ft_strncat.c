/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:14:13 by uheirloo          #+#    #+#             */
/*   Updated: 2019/09/10 17:21:59 by uheirloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, char const *s2, size_t n)
{
	char	*arr;
	size_t	i;

	arr = s1;
	i = 0;
	while (*arr)
	{
		arr++;
	}
	while (*s2 && i < n)
	{
		*arr = *s2;
		arr++;
		s2++;
		i++;
	}
	*arr = '\0';
	return (s1);
}
