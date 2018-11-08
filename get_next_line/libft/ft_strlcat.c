/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 19:23:38 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/25 18:42:10 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"

size_t		ft_strlcat(char *dst, const char *src,
	size_t size)
{
	size_t	i;
	size_t	j;
	size_t	rep;

	rep = (size_t)ft_strlen(dst) + (size_t)ft_strlen(src);
	i = 0;
	j = 0;
	if ((size_t)ft_strlen(dst) >= size)
		return (ft_strlen(src) + size);
	while (dst[i])
		i++;
	while (src[j] && ((i + 1) < size))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (rep);
}
