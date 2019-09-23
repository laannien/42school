/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:35:31 by uheirloo          #+#    #+#             */
/*   Updated: 2019/09/10 18:21:04 by uheirloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char const *s, int c)
{
	char *arr;

	arr = (char*)s;
	while (*arr)
	{
		if (*arr == c)
		{
			return (arr);
		}
		arr++;
	}
	if (*arr == '\0' && c == '\0')
	{
		return (arr);
	}
	return (NULL);
}
