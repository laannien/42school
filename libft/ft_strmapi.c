/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 18:12:11 by uheirloo          #+#    #+#             */
/*   Updated: 2019/09/14 11:16:36 by uheirloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*result;
	unsigned int		i;

	if (s != NULL)
	{
		i = 0;
		result = (char*)malloc(sizeof(*s) * (ft_strlen(s) + 1));
		if (result != NULL)
		{
			while (s[i] != '\0')
			{
				result[i] = (*f)(i, s[i]);
				i++;
			}
			result[i] = '\0';
			return (result);
		}
	}
	return (NULL);
}
