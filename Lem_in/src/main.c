/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/27 19:02:01 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/17 18:40:31 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../lem_in.h"

void	free_tabfile(t_lem *lemin)
{
	int	i;

	i = 0;
	while (lemin->tabfile[i] != NULL)
	{
		free(lemin->tabfile[i]);
		i++;
	}
}

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
	char	bool_visu;

	bool_visu = 0;
	if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'v')
		bool_visu = 1;
	init(&lemin);
	lem_parsing(&lemin);
	test(&lemin);
	if (!bool_visu)
		free_tabfile(&lemin);
	// L'appel a l'algo se placera ici
	if (bool_visu)
	{
		parse_coords(&lemin);
		free_tabfile(&lemin);
		visu_lemin(&lemin);
	}
	return (0);
}
