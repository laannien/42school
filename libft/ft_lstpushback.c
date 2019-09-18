/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <uheirloo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 12:52:58 by uheirloo          #+#    #+#             */
/*   Updated: 2019/09/18 13:13:01 by uheirloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushback(t_list **alst, t_list *new)
{
	t_list *elem;

	if (alst && new)
	{
		while ((*alst)->next != NULL)
		{
			(*alst)++;
		}
		elem = *alst;
		elem->next = new;
	}
	else if (!(*alst))
	{
		(*alst) = new;
	}
}
