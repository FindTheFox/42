/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:53:59 by saneveu           #+#    #+#             */
/*   Updated: 2018/11/08 18:03:42 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int				ft_atoi(char *str);
void			ft_bzero(void *s, size_t n);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
void			*ft_memalloc(size_t size);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memdel(void **ap);
void			*ft_memset(void *s, int i, size_t n);
char			*ft_strcat(char *dest, char *src);
char			*ft_strchr(const char *s, int c);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strcpy(char *dest, char *src);
void			ft_strdel(char **as);
int				ft_strlen(char *str);
char			*ft_strdup(char *src);
char			*ft_strncat(char *dest, char *src, unsigned int n);
int				ft_strncmp(char *s1, char *s2, unsigned int nb);
char			*ft_strncpy(char *dest, char *src, unsigned int n);
char			*ft_strnew(size_t size);
char			*ft_strnstr(char *str, char *to_find, unsigned int nb);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(char *str, char *to_find);
int				ft_tolower(int c);
int				ft_toupper(int c);
void			*ft_memmove(void *dest, const void *src, size_t n);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
 
#endif
