/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <uheirloo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:02:13 by uheirloo          #+#    #+#             */
/*   Updated: 2019/09/28 14:39:04 by uheirloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_get_line(char *content, char **line)
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
		return (NULL);
	}
	else if (content[i] == '\n')
	{
		tmp = ft_strsub(content, 0, i);
		*line = tmp;
		tmp = ft_strdup(content + i + 1);
		ft_strdel(&content);
		content = tmp;
		return (content);
	}
	return (content);
}

static t_line	*ft_new_elem(int fd)
{
	t_line	*new;

	new = (t_line*)malloc(sizeof(t_line));
	if (!new)
	{
		return (NULL);
	}
	else
	{
		new->content = (char*)malloc(sizeof(char) * 1);
		if (!new->content)
		{
			return (NULL);
		}
		ft_bzero(new->content, 1);
		new->fd = fd;
		new->next = NULL;
	}
	return (new);
}

static t_line	*ft_get_current(t_line *begin, const int fd)
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

static int		ft_read_file(t_line *current, char **line)
{
	int		length;
	char	buffer[BUFF_SIZE + 1];
	char	*tmp;

	tmp = NULL;
	if (!(tmp = ft_strchr(current->content, '\n')))
	{
		while ((length = read(current->fd, buffer, BUFF_SIZE)) > 0)
		{
			buffer[length] = '\0';
			if (!(tmp = ft_strjoin(current->content, buffer)))
				return (-1);
			free(current->content);
			current->content = tmp;
			if (ft_strchr(buffer, '\n'))
				break ;
		}
		if (length < 0)
			return (-1);
		if (length == 0 && current->content[0] == '\0')
			return (0);
	}
	current->content = ft_get_line(current->content, line);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_line	*begin;
	t_line			*current;

	if (fd < 0 || read(fd, NULL, 0) == -1 || BUFF_SIZE <= 0 ||\
		line == NULL)
		return (-1);
	if (begin == NULL)
	{
		current = ft_new_elem(fd);
		begin = current;
	}
	current = ft_get_current(begin, fd);
	if (current->content == NULL)
		return (0);
	return (ft_read_file(current, line));
}
