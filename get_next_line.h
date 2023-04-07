/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadane <asaadane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 22:30:07 by asaadane          #+#    #+#             */
/*   Updated: 2023/04/07 22:32:20 by asaadane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>

size_t			ft_strlen(char *str);

char			*ft_strchr(char *s, int c);
char			*ft_strjoin(char *s1, char *s2);
char			*get_next_line(int fd);
char			*ft_hold_line(char *hold);
char			*ft_sub_hold(char *hold, char *line);
char			*ft_read_and_hold(int fd, char *hold);


#endif