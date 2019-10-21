/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lem_parse_rooms.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 22:33:53 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/10/21 19:21:51 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

void	make_roomtab(t_lem *lem)
{
	int	i;
	int curs;

	lem->rooms = (t_rooms*)malloc(sizeof(t_rooms) * lem->nb_room);
	i = 0;
	curs = 2;
	while (i < lem->nb_room)
	{
		while (lem->tabfile[curs][0] == '#')
			curs++;
		lem->rooms[i].start = 0;
		lem->rooms[i].end = 0;
		lem->rooms[i].name = ft_strndup(lem->tabfile[curs],
			ft_strcspn(lem->tabfile[curs], " "));
		if (!ft_strcmp(lem->rooms[i].name, lem->start))
			lem->rooms[i].start = 1;
		if (!ft_strcmp(lem->rooms[i].name, lem->end))
			lem->rooms[i].end = 1;
		ft_printf("\nname = : %s\nstart = %d \nend = %d\n\n", lem->rooms[i].name, lem->rooms[i].start, lem->rooms[i].end); //ligne test
		i++;
		curs++;
	}
}

void	get_room_names(char **r1, char **r2, char *str)
{
	int	i;

	i = ft_strcspn(str, "-");
	*r1 = ft_strndup(str, i);
	*r2 = ft_strdup(str + i + 1);
}

void	fill_matrix(t_lem *lem)
{
	char	*r1;
	char	*r2;
	int		i;
	int		j;

	while (lem->tabfile[lem->curs])
	{
		i = 0;
		j = 0;
		get_room_names(&r1, &r2, lem->tabfile[lem->curs]);
		while (ft_strcmp(r1, lem->rooms[i].name))
			i++;
		while (ft_strcmp(r2, lem->rooms[j].name))
			j++;
		ft_strdel(&r1);
		ft_strdel(&r2);
		lem->room_matrix[i][j] = '1';
		lem->room_matrix[j][i] = '1';
		//ft_printf("\ni = %d j = %d\n", i, j);
		lem->curs++;
	}
}

void	init_matrix(t_lem *lem)
{
	int i;
	int j;

	lem->room_matrix = (char **)malloc(sizeof(char *) * lem->nb_room + 1);
	i = 0;
	while (i < lem->nb_room)
	{
		j = 0;
		lem->room_matrix[i] = (char *)malloc(sizeof(char) * lem->nb_room + 1);
		while (j < lem->nb_room)
		{
			lem->room_matrix[i][j] = '0';
			j++;
		}
		lem->room_matrix[i][j] = '\0';
		i++;
	}
	lem->room_matrix[i] = NULL;
}

void	parse_rooms(t_lem *lem)
{
	make_roomtab(lem);
	init_matrix(lem);
	fill_matrix(lem);
	//ft_printf("\nCURS = %s\n", lem->tabfile[lem->curs]);
}
