/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubblesort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <uheirloo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 13:07:36 by uheirloo          #+#    #+#             */
/*   Updated: 2019/09/18 13:36:43 by uheirloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_bubblesort(int *src, int size)
{
	int tmp;
	int i;
	int j;

	if (src)
	{
		j = 0;
		while (j < size)
		{
			i = 0;
			while (i < size - 1)
			{
				if (src[i] > src[i + 1])
				{
					tmp = src[i];
					src[i] = src[i + 1];
					src[i + 1] = tmp;
				}
				i++;
			}
			j++;
		}
		return (src);
	}
	return (0);
}
