/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <uheirloo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:17:48 by uheirloo          #+#    #+#             */
/*   Updated: 2019/09/18 14:28:47 by uheirloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new;

	new = (t_list*)malloc(sizeof(t_list));
	if (!new)
	{
		free(new);
		return (NULL);
	}
	if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
		new->next = NULL;
	}
	else
	{
		if (!(new->content = (void*)malloc(content_size)))
		{
			return (NULL);
		}
		new->content = ft_memcpy((new->content), content, content_size);
		new->content_size = content_size;
		new->next = NULL;
	}
	return (new);
}
