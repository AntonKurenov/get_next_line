/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 12:18:14 by elovegoo          #+#    #+#             */
/*   Updated: 2020/07/11 18:58:46 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		line_creator(char **line, int len, char *buff, int flag)
{
	if (flag ==  1)
	{
	
					
	}
	return (0);
}

char 	*rem_check(char **line, char *rem, int *ret)
{
	char *ptr;

	ptr = NULL;
	if (rem)
	{
		if ((ptr = ft_strchr(rem, '\n')))
		{
			*ptr = '\0';
			*line = ft_strjoin(rem, "");
			ft_strcpy(rem, ++ptr);
			*ret = 1;
		}
		else
			*line = ft_strjoin(rem, "");
	}
	else
		*line = ft_strjoin("", "");
	return (ptr);
}

int		get_next_line(int fd, char **line)
{
	static char	*rem;
	int 	total;
	char 	buff[BUFF_SIZE + 1];
	int 	ret;
	char 	*ptr;
	char 	*tmp;

	if (fd < 0)
		return (-1);
	ptr = rem_check(line, rem, &ret);
	while (!ptr && (total = read(fd, buff, BUFF_SIZE)))
	{
		printf("total = %d\n", total);
		buff[total] = '\0';
		printf("buff = %s\n", buff);
		if ((ptr = ft_strchr(buff, '\n')))
		{
			printf("inside if:\n");
			*ptr = '\0';
			tmp = rem;
			rem = ft_strjoin(++ptr, "");
			printf("rem = %s\n", rem);
			free(tmp);
			ret = 1;
		}
		tmp = *line;
		*line = ft_strjoin(*line, buff);
		free(tmp);
	}
	printf("len(rem) = %ld\n", ft_strlen(rem));
	if (ft_strlen(rem) == 0 && total < BUFF_SIZE)
		ret = 0;
	printf("total = %d\n", total);
	printf("ret = %d\n", ret);
	//if (total == 0)
		//return (0);
	return (ret);
}

int		main(void)
{
	int	fd;
	char *line;
	int		ret;

	//fd = open("only_one.txt", O_RDONLY);
	fd = open("new.txt", O_RDONLY);

	/*
	ret = get_next_line(fd, &line);
	printf("%s\t return value = %d \n\n", line, ret);
	free(line);
	ret = get_next_line(fd, &line);
	printf("%s\t return value = %d \n\n", line, ret);
	free(line);
	*/
///*
	while ((ret = get_next_line(fd, &line)))
	{
		printf("ret = %d || %s\n\n", ret, line);
		//free(line);
	}
	printf("ret = %d || %s\n\n", ret, line);
	//free(line);
	//*/
	
	close(fd);
	return (0);
}
