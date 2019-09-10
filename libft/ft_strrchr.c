/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:41:29 by uheirloo          #+#    #+#             */
/*   Updated: 2019/09/10 18:20:24 by uheirloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char const *s, int c)
{
	char *arr;

	arr = (char*)s;
	while (*arr)
	{
		arr++;
	}
	if (*arr == '\0' && c == '\0')
	{
		return (arr);
	}
	while (arr >= s)
	{
		if (*arr == c)
		{
			return (arr);
		}
		arr--;
	}
	return (NULL);
}
