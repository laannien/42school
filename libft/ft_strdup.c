/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:27:51 by uheirloo          #+#    #+#             */
/*   Updated: 2019/09/10 11:28:31 by uheirloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *s)
{
	int i;
	char *result;

	i = 0;
	result = (char*)malloc(sizeof(*s) * (ft_strlen(s) + 1));
	if (!result)
	{
		return (NULL);
	}
	while(s[i] != '\0')
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
