/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 19:44:38 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/25 18:42:10 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strtrim(char const *s)
{
	char			*buf;
	char			*rep;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (ft_tnrvf(s[i]))
		i++;
	if (!(buf = (char*)malloc(sizeof(char) * ft_strlen(s + i) + 1)))
		return (NULL);
	buf = ft_strcpy(buf, s + i);
	ft_strrev(buf);
	i = 0;
	while (ft_tnrvf(buf[i]))
		i++;
	if (!(rep = (char*)malloc(sizeof(char) * ft_strlen(buf + i) + 1)))
		return (NULL);
	rep = ft_strcpy(rep, buf + i);
	ft_strrev(rep);
	return (rep);
}
