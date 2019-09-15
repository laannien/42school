/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 11:21:43 by uheirloo          #+#    #+#             */
/*   Updated: 2019/09/14 12:56:59 by uheirloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;
	size_t	size;
	char	*result;

	if (s != NULL)
	{
		start = 0;
		while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		{
			start++;
		}
		end = ft_strlen(s);
		while (end != start && (s[end - 1] == ' ' || s[end - 1] == '\n' || s[end - 1] == '\t'))
		{
			end--;
		}
		size = end - start;
		result = (char*)malloc(sizeof(*s) * (size + 1));
		if (result != NULL)
		{
			result = ft_strncpy(result, &s[start], size);
			result[size] = '\0';
		}
		return (result);
	}
	return (NULL);
}
