/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:17:48 by uheirloo          #+#    #+#             */
/*   Updated: 2019/09/16 16:56:43 by uheirloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new;

	if (content == NULL)
	{
		content_size = 0;
	}
	new = (t_list*)malloc(sizeof(t_list));
	if (new)
	{
		new->content = (void*)content;
		new->content_size = content_size;
		new->next = NULL;
		return (new);
	}
	free(new);
	return (NULL);
}
