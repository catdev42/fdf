/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 19:22:22 by myakoven          #+#    #+#             */
/*   Updated: 2024/04/23 16:09:27 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

// # include "./get_next_line/get_next_line.h"
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);

size_t				ft_strlen(const char *s);

int					ft_toupper(int c);
int					ft_tolower(int c);

void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);

char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);

size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);

int					ft_atoi(const char *nptr);
long				ft_atol(const char *nptr);

void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_strdup(const char *s);

char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

char				**ft_split(char const *s, char c);
size_t				ft_wordcount(char const *s, char c);

void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

void				ft_freetab(char **arr, int len);
/* SINGLE LINKED LIST */

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **first, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

/*****************************************/
/**************** PRINTF *****************/
/*****************************************/

int					ft_printf(const char *string, ...);

int					ft_printchar(int c);
int					ft_printstr(char *str);
int					ft_printnum(int n);

int					ft_printuns(unsigned int u);

int					ft_printptr(uintptr_t address);
int					ft_printhex(unsigned int num, char format);
/*
static int			ft_checkcase(va_list args, const char format);
static int			ft_print_it_hex(unsigned int num, char format);
int					ft_strlen_printf(const char *s);
static char			*ft_uitoa_printf(unsigned int u);
static int			ft_unslen(unsigned int u);
static int			ft_print_it(uintptr_t address);
static char			*ft_itoa_printf(int n);
*/
/****GET_NEXT_LINE****/

char	*get_next_line(int fd);
char	*ft_read(int fd, char *line, char *buffer);
char	*ft_strjoinbuff(char *s1, char const *buff);
char	*ft_takeline(char *line, char *buffer);
char	*ft_clearfree(char *buffer, char *line);

// char				*get_next_line(int fd);
// char				*ft_read(int fd, char *line, char *buffer);
// char				*ft_strjoinbuff(char *s1, char const *buff);
// char				*ft_takeline(char *line, char *buffer);
// char				*ft_clearfree(char **buffer, char *line);

#endif