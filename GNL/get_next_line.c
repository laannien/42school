/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <uheirloo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:02:13 by uheirloo          #+#    #+#             */
/*   Updated: 2019/09/23 16:42:23 by uheirloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static void		ft_get_line(char *content, int length, char **line)
{
	char	*tmp;
	int		i;

	i = 0;
	while (content[i] != '\n' && content[i] != '\0')
		i++;
	if (content[i] == '\0')
	{
		*line = content;
		ft_strdel(&(*content));
	}
	else
	{
		tmp = ft_strsub(content, 0, i);
		*line = tmp;
		tmp = ft_strdup(content + i + 1);
		ft_strdel(&(*content));
		content = tmp;
		free(tmp);
	}
}

static t_list	*ft_get_current(t_list **begin, const int fd)
{
	while (*begin)
	{
		if ((*begin)->fd == fd)
		{
			return (*begin);
		}
		*begin = (*begin)->next;
	}
	(*begin)->next = new_elem(fd);
	return ((*begin)->next);
}

static t_list	*new_elem(int fd)
{
	t_list	*new;

	new = (t_list*)malloc(sizeof(t_list));
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

int				get_next_line(const int fd, char **line)
{
	static t_list	**begin;
	t_list			*current;
	char			buffer[BUFF_SIZE + 1];
	char			*tmp;
	int				length;

	if (begin == NULL)
	{
		current = new_elem(fd);
		begin = &current;
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
	if (length < 0)
		return (-1);
	if (length == 0 && (current->content == '\0'))
		return (0);
	ft_get_line(current->content, length, line);
	return (1);
}

int				main(int argc, char **argv)
{
	int		fd;
	char	*result;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	result = NULL;
	get_next_line(fd, &result);
	printf("%s", result);
	return (0);
}
