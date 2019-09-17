/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <uheirloo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 14:46:26 by uheirloo          #+#    #+#             */
/*   Updated: 2019/09/17 18:03:21 by uheirloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *lst;
	t_list *nxtlst;

	if (del && alst)
	{
		lst = *alst;
		while (lst)
		{
			nxtlst = lst->next;
			(*del)(lst->content, lst->content_size);
			free(lst);
			lst = nxtlst;
		}
		(*alst) = NULL;
	}
}
