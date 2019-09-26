/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <uheirloo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:02:13 by uheirloo          #+#    #+#             */
/*   Updated: 2019/09/26 17:51:41 by uheirloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Записывает строку (до \n|\0) в line и возвращает остаток
// Если мы дошли до \n возвращаем остаток после \n
// Если мы дошли до \0 возвращаем NULL
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
//		if (*content == '\0')
		ft_strdel(&content);
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

// Основная логика работы get_next_line
int		ft_read_file(t_line *current, char **line)
{
	int		length;
	char	buffer[BUFF_SIZE + 1];
	char	*tmp;

	tmp = NULL;
	// Если в текущем остатке нет \n
	if (!(ft_strchr(current->content, '\n')))
	{
		// Читаем содержимое файла в буфер пока не дойдём до конца, либо до буфера с \n
		while ((length = read(current->fd, buffer, BUFF_SIZE)) > 0)
		{
			// Завершаем прочитанную строку \0
			buffer[length] = '\0';
			// Прибавляем к остатку прочитанный буфер
			tmp = ft_strjoin(current->content, buffer);
			// Если не удалось выделить память, возвращаем ошибку
			if (tmp == NULL)
				return (-1);
			free(current->content);
			// Записываем новый остаток
			current->content = tmp;
			// Выходим из цикла если в буфере есть \n
			if (ft_strchr(buffer, '\n'))
				break ;
		}
		if (length < 0)
			return (-1);
		if (length == 0 && (current->content == '\0'))
			return (0);
	}
	if (current->content == '\0')
		return (0);
	// Пишем первую строку из остатка в line и возвращаем остаток в остаток :)
	current->content = ft_get_line(current->content, line);
//	if (length == 0 && current->content)
//	{
//		ft_strdel(&current->content);
//		return (1);
//	}

	// if (current->content == NULL || current->content == '\0')
	// 	return (0);
	return (1);
}

// Осуществляет построчное чтение файла, записывая текущую строку в line
// При последующем вызове мы получаем следующую строку файла
// Возвращает 1 если мы записали в line строку
// Возвращает 0 если мы стояли на конце файла и ничего не получили
// Вовращает -1 если была ошибка
int		get_next_line(const int fd, char **line)
{
	// Список нужен для хранения данных с разных файлов
	static t_line	*begin; // Первый элемент списка
	t_line			*current;

	if (fd < 0 || read(fd, NULL, 0) == -1 || BUFF_SIZE <= 0 ||\
		line == NULL)
		return (-1);
	if (begin == NULL)
	{
		begin = ft_new_elem(fd);
	}
	current = ft_get_current(begin, fd);
	return (ft_read_file(current, line));
}
