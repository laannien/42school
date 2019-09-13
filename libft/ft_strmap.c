/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 18:12:11 by uheirloo          #+#    #+#             */
/*   Updated: 2019/09/13 18:20:06 by uheirloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*result;
	int		i;

	if (s != NULL)
	{
		i = 0;
		result = (char*)malloc(sizeof(*s) * (ft_strlen(s) + 1));
		if (result != NULL)
		{
			while (s[i] != '\0')
			{
				result[i] = (*f)(s[i]);
				i++;
			}
			result[i] = '\0';
			return (result);
		}
	}
	return (NULL);
}
