/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lem_parse_coords.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/21 17:59:15 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/18 04:35:55 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../lem_in.h"

void			destroy_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		ft_strdel(&tab[i]);
}

void			data_for_window(t_lem *lem)
{
	int		i;

	i = 1;
	lem->biggestxcoord = lem->room_coords[0][0];
	lem->biggestycoord = lem->room_coords[0][1];
	while (i < lem->nb_room)
	{
		if (lem->biggestxcoord < lem->room_coords[i][0])
			lem->biggestxcoord = lem->room_coords[i][0];
		if (lem->biggestycoord < lem->room_coords[i][1])
			lem->biggestycoord = lem->room_coords[i][1];
		i++;
	}
}

static	void	get_coords(t_lem *lem, int i, int curs)
{
	char	**tab;

	tab = ft_strsplit(lem->tabfile[curs], ' ');
	lem->room_coords[i] = (int*)malloc(sizeof(int) * 2);
	lem->room_coords[i][0] = ft_atoi(tab[1]);
	if (lem->room_coords[i][0] < 10)
		lem->room_coords[i][0] *= 100;
	lem->room_coords[i][1] = ft_atoi(tab[2]);
	if (lem->room_coords[i][1] < 10)
		lem->room_coords[i][1] *= 100;
	destroy_tab(tab);
}

void			parse_coords(t_lem *lem)
{
	int		curs;
	int		i;

	lem->room_coords = (int**)malloc(sizeof(int*) * lem->nb_room);
	curs = 2;
	i = 1;
	while (i < lem->nb_room - 1)
	{
		while (lem->tabfile[curs][0] == '#')
			curs++;
		get_coords(lem, i, curs);
		if (curs == lem->startindex || curs == lem->endindex)
		{
			free(lem->room_coords[i]);
			i--;
		}
		curs++;
		i++;
	}
	get_coords(lem, 0, lem->startindex);
	get_coords(lem, lem->nb_room - 1, lem->endindex);
	i = 0;
	data_for_window(lem);
}
