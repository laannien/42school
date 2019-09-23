/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <uheirloo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 13:49:10 by uheirloo          #+#    #+#             */
/*   Updated: 2019/09/18 14:12:32 by uheirloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char *src)
{
	size_t	i;
	size_t	len;
	char	tmp;

	if (src)
	{
		i = 0;
		len = ft_strlen(src) - 1;
		while (i < len)
		{
			tmp = src[i];
			src[i] = src[len];
			src[len] = tmp;
			i++;
			len--;
		}
	}
}
