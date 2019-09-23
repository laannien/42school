/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <uheirloo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:08:59 by uheirloo          #+#    #+#             */
/*   Updated: 2019/09/17 18:07:14 by uheirloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;

	if (!lst || !(*f))
	{
		return (NULL);
	}
	tmp = NULL;
	if (lst)
	{
		tmp = (*f)(lst);
		if (!tmp)
		{
			free(tmp);
			return (NULL);
		}
		else
		{
			tmp->next = ft_lstmap(lst->next, &(*f));
		}
	}
	return (tmp);
}
