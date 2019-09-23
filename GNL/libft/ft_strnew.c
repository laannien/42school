/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:28:43 by uheirloo          #+#    #+#             */
/*   Updated: 2019/09/14 16:10:42 by uheirloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *result;

	if (size > size + 1)
	{
		return (NULL);
	}
	result = (char*)malloc(sizeof(char) * (size + 1));
	if (!result)
	{
		return (NULL);
	}
	ft_bzero(result, size + 1);
	return (result);
}
