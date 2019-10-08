/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/27 19:02:01 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/10/08 23:40:04 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

void	init(t_lem *lemin)
{
	lemin->nb_ant = 0;
	lemin->start = NULL;
	lemin->end = NULL;
	lemin->startfound = 0;
	lemin->endfound = 0;
}

int		main(void)
{
	t_lem	lemin;

	init(&lemin);
	lem_parsing(&lemin);
	test(&lemin);
	return (0);
}
