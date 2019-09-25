/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <uheirloo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 12:20:16 by uheirloo          #+#    #+#             */
/*   Updated: 2019/09/25 14:37:05 by uheirloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int				main(int argc, char **argv)
{
	int		fd1;
	int		fd2;
	int		gnl;
	char	*result;

	(void)argc;
	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);
	result = NULL;
	gnl = get_next_line(fd1, &result);
	printf("%d %s\n", gnl, result);
	get_next_line(fd2, &result);
	printf("%s\n", result);
	get_next_line(fd1, &result);
	printf("%s\n", result);
	get_next_line(fd2, &result);
	printf("%s\n", result);
	get_next_line(fd1, &result);
	printf("%s\n", result);
	ft_strdel(&result);
	gnl = get_next_line(fd1, &result);
	printf("%d %s\n", gnl, result);
	close(fd1);
	close(fd2);
	return (0);
}
