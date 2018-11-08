/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/24 18:58:43 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/30 19:30:31 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_use_overflow(char **overflow, char **line)
{
	char	*tmpoverflow;

	if (!(*line = ft_strndup(*overflow, ft_strcspn(*overflow, "\n"))))
		return (-1);
	if (ft_strchr(*overflow, '\n'))
	{
		tmpoverflow = ft_strdup(*overflow + ft_strcspn(*overflow, "\n") + 1);
		if (!tmpoverflow)
			return (-1);
	}
	else
		tmpoverflow = NULL;
	if (tmpoverflow)
	{
		ft_strdel(overflow);
		*overflow = tmpoverflow;
	}
	else
		ft_strdel(overflow);
	if (*line[0] == '\0' && !*overflow)
		return (0);
	return (1);
}

static int		ft_read_file(int fd, char **line, char **overflow)
{
	int		rbytes;
	char	buffer[BUFF_SIZE + 1];
	char	*jointmp;
	int		returnvalue;

	while ((rbytes = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[rbytes] = '\0';
		if (!(jointmp = ft_strjoin(*overflow, buffer)))
			return (-1);
		ft_strdel(overflow);
		*overflow = jointmp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	returnvalue = ft_use_overflow(overflow, line);
	return (returnvalue);
}

int				get_next_line(int fd, char **line)
{
	static char	*overflow[5000];
	int			returnvalue;

	if (fd >= 5000)
		return (-1);
	if ((fd < 0 || !line || BUFF_SIZE <= 0 || read(fd, overflow[fd], 0) < 0))
		return (-1);
	if (!overflow[fd])
	{
		if (!(overflow[fd] = ft_memalloc(1)))
			return (-1);
	}
	returnvalue = (ft_read_file(fd, line, &overflow[fd]));
	return (returnvalue);
}
