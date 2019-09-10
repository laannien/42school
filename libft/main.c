/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:29:30 by uheirloo          #+#    #+#             */
/*   Updated: 2019/09/10 14:49:19 by uheirloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		main(void)
{
	ft_putchar('w');
	ft_putchar('\n');
	ft_putstr("Hello\n");
	ft_putstr(ft_strdup("world\n"));
	printf("%zu\n", ft_strlen("0123456789"));
	printf("%d\n", ft_isalnum(-55));
	return (0);
}
