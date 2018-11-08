/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 21:22:57 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/25 18:42:10 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_itoa(int n)
{
	char			*rep;
	unsigned int	nb;
	int				i;

	i = 0;
	if (!(rep = (char*)malloc(sizeof(char) * ft_intlen(n) + 1)))
		return (NULL);
	nb = (n < 0 ? -n : n);
	while (nb)
	{
		rep[i++] = (nb % 10) + '0';
		nb /= 10;
	}
	if (n <= 0)
		rep[i++] = (n == 0 ? '0' : '-');
	rep[i] = '\0';
	ft_strrev(rep);
	return (rep);
}
