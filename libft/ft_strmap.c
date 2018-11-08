/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 18:49:42 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/25 18:42:10 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*rep;
	int		i;

	if (f)
	{
		i = 0;
		if (!(rep = ft_strnew(ft_strlen((char*)s))))
			return (NULL);
		while (s[i])
		{
			rep[i] = f(s[i]);
			i++;
		}
		return (rep);
	}
	return (NULL);
}
