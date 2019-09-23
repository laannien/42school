/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 13:18:09 by uheirloo          #+#    #+#             */
/*   Updated: 2019/09/12 14:48:07 by uheirloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char const *haystack, char const *needle)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*needle == '\0')
	{
		return ((char*)haystack);
	}
	while (haystack[i] != '\0')
	{
		j = 0;
		while (haystack[i + j] == needle[j])
		{
			if (needle[j + 1] == '\0')
			{
				return ((char*)&haystack[i]);
			}
			else
			{
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
