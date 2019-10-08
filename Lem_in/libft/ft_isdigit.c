/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_isdigit.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jde-la-m <jde-la-m@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 13:57:52 by jde-la-m     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 14:02:15 by jde-la-m    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/*
**		DESCRIPTION
**	Checks for a digit (0 through 9).
*/

#include "libft.h"

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}
