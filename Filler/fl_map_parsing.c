/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fl_map_parsing.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/11 21:13:04 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/07/11 21:14:37 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

void	fl_make_map(t_init *fl, int lc, int i, int numline)
{
	if (fl->line[lc] == '.')
		fl->map[numline][i] = 0;
	else if (fl->line[lc] == 'O' || fl->line[lc] == 'o')
		fl->map[numline][i] = 1;
	else
		fl->map[numline][i] = 2;
}

void	fl_parse_map(t_init *fl)
{
	int		numline;
	int		lc;
	int		i;

	if (!(fl->map = ft_memalloc(sizeof(int *) * fl->height)))
		return ;
	numline = 0;
	if (fl->turn > 0)
		get_next_line(0, &fl->line);
	fl->turn++;
	while (numline < fl->height)
	{
		lc = 4;
		i = 0;
		if (!(fl->map[numline] = ft_memalloc(sizeof(int *) * fl->width)))
			emergency_free(fl->map, numline);
		get_next_line(0, &fl->line);
		while (lc < fl->width + 4)
			fl_make_map(fl, lc++, i++, numline);
		numline++;
	}
}
