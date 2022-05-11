/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 19:03:19 by mskeleto          #+#    #+#             */
/*   Updated: 2020/12/31 19:53:32 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

void	*ft_calloc(size_t number, size_t size);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_nsymbol(char *str);
int		ft_result(int status);
int		ft_check_remain(char ***line, char **remain);
int		get_next_line(int fd, char **line);
int		ft_zero(char *buffer, int i);
size_t	ft_strlen(const char *s);

#endif
