/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 14:45:59 by uheirloo          #+#    #+#             */
/*   Updated: 2019/09/14 14:56:12 by uheirloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *result;

	result = (void*)malloc(size);
	if (!result)
	{
		return (NULL);
	}
	else
	{
		ft_bzero(result, size);
		return (result);
	}
}
