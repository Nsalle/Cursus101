/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/05 17:41:33 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/25 18:42:10 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ptr;
	unsigned char	*ptsrc;

	ptr = (unsigned char*)dst;
	ptsrc = (unsigned char*)src;
	while (n--)
	{
		*ptr = *ptsrc;
		ptr++;
		ptsrc++;
	}
	return (dst);
}
