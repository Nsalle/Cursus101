/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lem_parsing.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/08 17:23:20 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/10/08 23:26:58 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

char	*clean_join(char *s1, char *s2)
{
	char	*ret;
	int i;
	int	j;

	i = 0;
	j = 0;

	ret = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 2);
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}		
	while(s2[j])
	{
		ret[i] = s2[j++];
		i++;
	}
	ret[i] = '\n';
	ret[i + 1] = '\0';
	ft_strdel(&s1);
	ft_strdel(&s2);
	return (ret);
}

char	*file_to_line(void)
{
	char	*line;
	char	*ret;

	ret = ft_strdup("HEAD\n");
	while(get_next_line(0, &line))
		ret = clean_join(ret, line);
	return (ret);
}

void	check_com(t_lem *lem)
{
	if (!(ft_strcmp(lem->tabfile[lem->curs], "##start" )))
	{
		lem->start = ft_strdup(lem->tabfile[lem->curs + 1]);
		lem->curs+=2;
		lem->nb_room++;
		lem->startfound++;
	}
	else if (!(ft_strcmp(lem->tabfile[lem->curs], "##end" )))
	{
		lem->end = ft_strdup(lem->tabfile[lem->curs + 1]);
		lem->curs+=2;
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
	while(42)
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
	// int i = 0;
	// while (lem->tabfile[i])
	// {
	// 	ft_putendl(lem->tabfile[i]);
	// 	i++;
	// }
}
