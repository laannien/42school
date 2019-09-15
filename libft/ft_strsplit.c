/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 16:35:24 by uheirloo          #+#    #+#             */
/*   Updated: 2019/09/14 17:03:57 by uheirloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_fill_arr(char *dest, char const *str, char c)
{
	size_t	i;

	if (str != NULL)
	{
		i = 0;
		while (str[i] != c && str[i] != '\0')
		{
			dest[i] = str[i];
			i++;
		}
		dest[i] = '\0';
		return (dest);
	}
	return (NULL);
}

size_t	ft_word_len(char const *s, char c)
{
	size_t i;

	if (s != NULL)
	{
		i = 0;
		while (s[i] != c)
		{
			i++;
		}
		return (i);
	}
	return (0);
}

size_t	ft_words(char const *s, char c)
{
	size_t i;
	size_t counter;

	if (s != NULL)
	{
		i = 0;
		counter = 0;
		while (s[i] != '\0')
		{
			if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			{
				counter++;
			}
			i++;
		}
		return (counter);
	}
	return (0);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**result;
	size_t	words;
	size_t	word_len;
	size_t	i;
	size_t	j;

	if (s != NULL)
	{
		i = 0;
		words = ft_words(s, c);
		if (!(result = (char**)malloc(sizeof(s) * words)))
		{
			free(result);
			return (NULL);
		}
		j = 0;
		while (s[i] != '\0' && j < words)
		{
			if (s[i] == c)
			{
				i++;
			}
			else
			{
				word_len = ft_word_len(&s[i], c);
				if (!(*(result + j) = (char*)malloc(sizeof(*s) * (word_len + 1))))
				{
					free(*(result + j));
					return (NULL);
				}
				result[j] = ft_fill_arr(*(result + j), &s[i], c);
				j++;
				i = i + word_len;
			}
		}
		return(result);
	}
	return (NULL);
}
