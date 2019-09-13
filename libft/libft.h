/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 18:08:13 by uheirloo          #+#    #+#             */
/*   Updated: 2019/09/13 11:34:22 by uheirloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

void	ft_putchar(char c);
void	ft_putstr(char const *s);
void	*ft_memchr(void const *s, int c, size_t n);
void	*ft_memcpy(void *dst, void const *src, size_t n);
void	*ft_memccpy(void *dst, void const *src, int c, size_t n);
char	*ft_strdup(char const *s);
char	*ft_strcpy(char *dest, char const *src);
char	*ft_strncpy(char *dest, char const *src, size_t n);
char	*ft_strcat(char *s1, char const *s2);
char	*ft_strncat(char *s1, char const *s2, size_t n);
char	*ft_strchr(char const *s, int c);
char	*ft_strrchr(char const *s, int c);
char	*ft_strnstr(char const *haystack, char const *needle, size_t len);
char	*ft_strstr(char const *haystack, char const *needle);
int		ft_strcmp(char const *s1, char const *s2);
int		ft_strncmp(char const *s1, char const *s2, size_t n);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_isspace(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_memcmp(void const *s1, void const *s2, size_t n);
size_t	ft_strlen(char const *s);

#endif
