/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:35:41 by uheirloo          #+#    #+#             */
/*   Updated: 2019/09/16 14:05:34 by uheirloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strnlen(char const *s, size_t maxlen)
{
	size_t len;

	if (s != NULL)
	{
		len = 0;
		while (s[len] != '\0' && len < maxlen)
		{
			len++;
		}
		return (len);
	}
	return (0);
}
