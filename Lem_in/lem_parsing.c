/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lem_parsing.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/08 17:23:20 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/10/21 17:21:01 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

int		skip_multiple_coms(t_lem *lem)
{
	int	i;

	i = 0;
	while (lem->tabfile[lem->curs + i][0] == '#')
		i++;
	return (i);
}

void	check_com(t_lem *lem)
{
	int		i;
	char	*tmp;

	i = skip_multiple_coms(lem);
	if (!(ft_strcmp(lem->tabfile[lem->curs], "##start")))
	{
		tmp = ft_strdup(lem->tabfile[lem->curs + i]);
		lem->start = ft_strndup(tmp, ft_strcspn(tmp, " "));
		ft_strdel(&tmp);
		lem->curs += i + 1;
		lem->nb_room++;
		lem->startfound++;
	}
	else if (!(ft_strcmp(lem->tabfile[lem->curs], "##end")))
	{
		tmp = ft_strdup(lem->tabfile[lem->curs + i]);
		lem->end = ft_strndup(tmp, ft_strcspn(tmp, " "));
		ft_strdel(&tmp);
		lem->curs += 1 + i;
		lem->nb_room++;
		lem->endfound++;
	}
	else
		lem->curs++;
}

void	get_nb_ants(t_lem *lem)
{
	lem->nb_ant = ft_atoi(lem->tabfile[1]);
	if (lem->nb_ant < 1 || lem->nb_ant > 2147483647)
	{
		ft_putstr_fd("Wrong number of ants, set : [1 to 2147483647]\n", 2);
		exit_early_parsing(lem);
	}
}

void	get_nb_rooms(t_lem *lem)
{
	while (42)
	{
		if (lem->tabfile[lem->curs][0] == '#')
			check_com(lem);
		else if (ft_strchr(lem->tabfile[lem->curs], '-'))
			break ;
		else
		{
			lem->nb_room++;
			lem->curs++;
		}
	}
	ft_printf("NBROOMS %d\n", lem->nb_room);
	if (lem->nb_room == 0 || lem->startfound != 1 || lem->endfound != 1)
	{
		if (lem->start)
			free(lem->start);
		if (lem->end)
			free(lem->end);
		ft_putendl_fd("Stricly need one starting and ending room", 2);
		exit_early_parsing(lem);
	}
}

void	lem_parsing(t_lem *lem)
{
	char	*linefile;

	lem->curs = 2;
	linefile = file_to_line();
	lem->tabfile = ft_strsplit(linefile, '\n');
	get_nb_ants(lem);
	get_nb_rooms(lem);
	ft_strdel(&linefile);
	parse_rooms(lem);
}
