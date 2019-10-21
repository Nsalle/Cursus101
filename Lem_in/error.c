/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   error.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/27 23:54:33 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/10/17 17:47:47 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

void	exit_early_parsing(t_lem *lem)
{
	int	i;

	i = 0;
	while (lem->tabfile[i])
	{
		ft_strdel(&lem->tabfile[i]);
		i++;
	}
	ft_putendl_fd("ERROR", 2);
	exit(0);
}
