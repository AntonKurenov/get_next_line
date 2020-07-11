/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 11:09:50 by elovegoo          #+#    #+#             */
/*   Updated: 2020/07/11 18:41:47 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> //remove that
#define BUFF_SIZE 2

typedef struct 			s_next_line
{
	int 				fd;
	char 				*rem;
	struct s_next_line	*next;
}						t_line;

char					*ft_strchr(const char *str, int c);
size_t					ft_strlen(const char *s);
char					*ft_strjoin(char const *s1, char const *s2);
int						get_next_line(int fd, char **line);
int						next_line(int fd, char **line, char **rem);
void 					del_str(char **str);
t_line					*new_elem(int fd);
char					*ft_strcpy(char *dest, const char *src);



#endif
