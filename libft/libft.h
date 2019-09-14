/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 18:08:13 by uheirloo          #+#    #+#             */
/*   Updated: 2019/09/14 16:49:17 by uheirloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

void	ft_putchar(char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr(char const *s);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putendl(char const *s);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putnbr(int n);
void	ft_putnbr_fd(int n, int fd);
void	ft_bzero(void *s, size_t n);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_strdel(char **as);
void	ft_strclr(char *s);
void	ft_memdel(void **ap);
void	*ft_memchr(void const *s, int c, size_t n);
void	*ft_memcpy(void *dst, void const *src, size_t n);
void	*ft_memccpy(void *dst, void const *src, int c, size_t n);
void	*ft_memmove(void *dst, void const *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memalloc(size_t size);
char	*ft_strnew(size_t size);
char	*ft_strdup(char const *s);
char	*ft_strcpy(char *dest, char const *src);
char	*ft_strncpy(char *dest, char const *src, size_t n);
char	*ft_strcat(char *s1, char const *s2);
char	*ft_strncat(char *s1, char const *s2, size_t n);
char	*ft_strchr(char const *s, int c);
char	*ft_strrchr(char const *s, int c);
char	*ft_strnstr(char const *haystack, char const *needle, size_t len);
char	*ft_strstr(char const *haystack, char const *needle);
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_itoa(int n);
int		ft_atoi(char const *str);
int		ft_strcmp(char const *s1, char const *s2);
int		ft_strncmp(char const *s1, char const *s2, size_t n);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
int		ft_strequ(char const *s1, char const *s2);
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
