/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 13:43:00 by gyroh             #+#    #+#             */
/*   Updated: 2022/11/18 20:20:49 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 30
//# endif

//# ifndef OPEN_MAX
//#  define OPEN_MAX 10240
//# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>


int		check_newline(char *line);
char	*get_newline(char **line, int rsize);
char	*get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(char *src);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);

#endif
