/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <uheirloo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:02:13 by uheirloo          #+#    #+#             */
/*   Updated: 2019/09/24 16:49:08 by uheirloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char		*ft_get_line(char *content, char **line)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	while (content[i] != '\n' && content[i] != '\0')
		i++;
	if (content[i] == '\0')
	{
		*line = content;
		/*ft_strdel(&content);*/
		return (NULL);
	}
	else
	{
		tmp = ft_strsub(content, 0, i);
		*line = tmp;
		tmp = ft_strdup(content + i + 1);
		/*ft_strdel(&content);*/
		content = tmp;
		return (content);
	}
}

t_line	*ft_new_elem(int fd)
{
	t_line	*new;

	new = (t_line*)malloc(sizeof(t_line));
	if (!new)
	{
		return (NULL);
	}
	else
	{
		new->content = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1));
		if (!new->content)
		{
			return (NULL);
		}
		ft_bzero(new->content, BUFF_SIZE + 1);
		new->fd = fd;
		new->next = NULL;
	}
	return (new);
}

t_line	*ft_get_current(t_line *begin, const int fd)
{
	while (begin->next)
	{
		if (begin->fd == fd)
		{
			return (begin);
		}
		begin = begin->next;
	}
	if (begin->fd == fd)
	{
		return (begin);
	}
	begin->next = ft_new_elem(fd);
	return (begin->next);
}

int				get_next_line(const int fd, char **line)
{
	static t_line	*begin;
	t_line			*current;
	char			buffer[BUFF_SIZE + 1];
	char			*tmp;
	int				length;

	if (begin == NULL)
	{
		current = ft_new_elem(fd);
		begin = current;
	}
	current = ft_get_current(begin, fd);
	while ((length = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[length] = '\0';
		tmp = ft_strjoin(current->content, buffer);
		free(current->content);
		current->content = tmp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	/*free(tmp);*/
	if (length < 0)
		return (-1);
	if (length == 0 && (current->content == '\0'))
		return (0);
	current->content = ft_get_line(current->content, line);
	return (1);
}

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
	get_next_line(fd2, &result);
	printf("%s\n", result);
	ft_strdel(&result);
	gnl = get_next_line(fd1, &result);
	printf("%d %s\n", gnl, result);
	close(fd1);
	close(fd2);
	return (0);
}
