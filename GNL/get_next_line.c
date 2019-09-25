/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <uheirloo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:02:13 by uheirloo          #+#    #+#             */
/*   Updated: 2019/09/25 17:51:05 by uheirloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *content, char **line)
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
		ft_strdel(&content);
		return (NULL);
	}
	else
	{
		tmp = ft_strsub(content, 0, i);
		*line = tmp;
		tmp = ft_strdup(content + i + 1);
		ft_strdel(&content);
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

int		ft_read_file(const int fd, t_line *current, char **line)
{
	int		length;
	char	buffer[BUFF_SIZE + 1];
	char	*tmp;

	tmp = NULL;
	while ((length = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[length] = '\0';
		tmp = ft_strjoin(current->content, buffer);
		free(current->content);
		current->content = tmp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (length < 0)
		return (-1);
	current->content = ft_get_line(current->content, line);
	if (length == 0)
		return (0);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static t_line	*begin;
	t_line			*current;
	/*int				ret;*/

	if (fd < 0 || read(fd, NULL, 0) == -1 || BUFF_SIZE <= 0 ||\
		line == NULL)
		return (-1);
	if (begin == NULL)
	{
		current = ft_new_elem(fd);
		begin = current;
	}
	current = ft_get_current(begin, fd);
	return (ft_read_file(fd, current, line));
}
