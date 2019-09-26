/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <uheirloo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:02:09 by uheirloo          #+#    #+#             */
/*   Updated: 2019/09/26 17:15:25 by uheirloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 50

# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <fcntl.h>
# include "./libft/libft.h"

typedef struct	s_line
{
	// Файловый дескриптор
	int				fd;
	// Оставшийся контент, прочитанный read-ом, но необработанный в текущем вызове функции
	char			*content;
	struct s_line	*next;
}				t_line;

int				get_next_line(const int fd, char **line);
//int				ft_read_file(const int fd, t_line *current, char **line);
//t_line			*ft_get_current(t_line *begin, const int fd);
//t_line			*ft_new_elem(int fd);
//char			*ft_get_line(char *content, char **line, int length);

#endif
