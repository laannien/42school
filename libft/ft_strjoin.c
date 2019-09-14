/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 16:35:24 by uheirloo          #+#    #+#             */
/*   Updated: 2019/09/14 17:03:57 by uheirloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		size;
	char		*result;

	if (!s1 || !s2)
	{
		return (NULL);
	}
	size = ft_strlen(s1) + ft_strlen(s2);
	result = (char*)malloc(sizeof(*s1) * (size + 1));
	if (!result)
	{
		return (NULL);
	}
	*result = 0;
	ft_strcat(result, s1);
	ft_strcat(result, s2);
	return (result);
}
