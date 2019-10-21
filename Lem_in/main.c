/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/27 19:02:01 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/10/21 17:58:31 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

void	init(t_lem *lemin)
{
	lemin->nb_ant = 0;
	lemin->nb_room = 0;
	lemin->start = NULL;
	lemin->end = NULL;
	lemin->startfound = 0;
	lemin->endfound = 0;
}

int		main(int argc, char **argv)
{
	t_lem	lemin;
	
	init(&lemin);
	lem_parsing(&lemin);
	test(&lemin);
	if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'v')
	{
		parse_coords(&lemin);
		visu_lemin(&lemin);
	}
	return (0);
}
