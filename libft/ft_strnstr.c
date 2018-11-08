/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 17:02:49 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/25 18:42:10 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (ft_strcmp(needle, "") == 0)
		return ((char*)haystack);
	while (haystack[i])
	{
		while (haystack[i] && i < len)
		{
			j = 0;
			while (haystack[i + j] == needle[j] && i + j <= len)
			{
				j++;
				if (needle[j] == '\0')
					return ((char*)haystack + i);
			}
			i++;
			if (haystack[i] == 0)
				return (NULL);
		}
		i++;
	}
	return (NULL);
}
