/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:02:43 by truello           #+#    #+#             */
/*   Updated: 2024/03/15 18:00:53 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>

# define TRUE 1
# define FALSE 0

void	*ft_calloc(size_t count, size_t size);
int		ft_free(void *ptr);

char	**ft_split(char const *str, char c);
char	**free_parts(char **parts);
int		get_parts_size(char **parts);

int		ft_isdigit(int c);
int		ft_isnum(char *str);

int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(char *s1, char *s2, int n);
char	*ft_strnewjoin(char *s1, char *s2);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strncpy(char *to_copy, size_t n);
void	ft_strrepl(char *str, char bef, char aft);
int		ft_strchr_i(char *str, char c);

int		ft_atoi(const char *str);
long	ft_atol(const char *str);
int		ft_strlen(const char *str);

void	ft_error(const char *str);

void	ft_swap_int(int *a, int *b);

int		has_int_parts(char *line, char delimiter);
int		is_int_parts(char **parts);

int		get_file_size(char *file_path);
char	*get_file_content(char *file_path);

int		ft_max(int x, int y);
double	ft_dmax(double x, double y);
int		ft_min(int x, int y);
double	ft_dmin(double x, double y);

#endif
